#include "common.h"
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#define SOLUTION 4
#if SOLUTION == 1
// 注意链表末尾的判断
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    return merge_sort(head, nullptr);
  }
  ListNode* merge_sort(ListNode *head, ListNode *tail) {
    if (head == tail || head->next == tail) return head;
    // find median
    ListNode *slow=head, *fast=head;
    while (fast != tail && fast->next != tail) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *left = merge_sort(head, slow);
    ListNode *right = merge_sort(slow, tail);
    ListNode *new_head = nullptr;
    ListNode **r = &new_head;
    while (left != slow && right != tail) {
      if (left->val < right->val) {
        *r = left;
        left = left->next;
      } else {
        *r = right;
        right = right->next;
      }
      r = &((*r)->next);
    }
    if (left != slow) {
      *r = left;
      while(left->next != slow) left = left->next;
      left->next = tail;
    } else if (right != tail) {
      *r = right;
      while(right->next != tail) right = right->next;
    }
    return new_head;
  }
};

#elif SOLUTION == 2

class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *slow=head, *fast=head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *right = sortList(slow->next);
    slow->next = nullptr;
    ListNode *left = sortList(head);
    ListNode *new_head = nullptr;
    ListNode **r = &new_head;
    while (left && right) {
      if (left->val < right->val) {
        *r = left;
        left = left->next;
      } else {
        *r = right;
        right = right->next;
      }
      r = &((*r)->next);
    }
    *r = left ? left : right;
    return new_head;
  }
};

#elif SOLUTION == 3

// Bad Quick Sort, More than 1s :( [WIP]
// 每次递归至少排好一个
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    return QuickSort(head);
  }
  ListNode* QuickSort(ListNode *start) {
    if (!start || !start->next) return start;
    ListNode *left = nullptr, *right = nullptr;
    ListNode **pleft = &left, **pright = &right;
    int k = start->val;
    for (ListNode *p = start; p; p = p->next) {
      if (p->val <= k) {
        *pleft = p;
        pleft = &((*pleft)->next);
      } else {
        *pright = p;
        pright = &((*pright)->next);
      }
    }
    *pleft = nullptr;
    *pright = nullptr;
    if (!right) {
      // start is maximum
      left = QuickSort(start->next); 
      right = start;
      start->next = nullptr;
    } else {
      left = QuickSort(left);
      right = QuickSort(right);
    }
    if (left) {
      if (right) {
        ListNode *p = left;
        while (p->next) {
          p = p->next;
        }
        p->next = right;
      }
    } else {
      return right;
    }
    return left;
  }
};

#elif SOLUTION == 4

// Good Quick Sort 44ms
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode left(0), mid(0), right(0); 
    ListNode *pleft=&left, *pmid=&mid, *pright=&right;
    int pv = head->val;
    for (;head;head=head->next) {
      int &val = head->val;
      if (val < pv) {
        AddNode(pleft, head);
      } else if (val == pv) {
        AddNode(pmid, head);
      } else {
        AddNode(pright, head);
      }
    }
    pleft->next = nullptr;
    pmid->next = nullptr;
    pright->next = nullptr;
    left.next = sortList(left.next);
    right.next = sortList(right.next);
    // concat left->next + mid->next + right->next
    ListNode res(0);
    ListNode *p = &res;
    AddLink(p, left.next);
    AddLink(p, mid.next);
    AddLink(p, right.next);
    return res.next;
  }
private:
  inline void AddNode(ListNode *&r, ListNode *p) {
    r->next = p;
    r = p;
  }
  void AddLink(ListNode *&r, ListNode *p) {
    if (p) {
      r->next = p;
      r = p;
      while (r->next) r = r->next;
    }
  }
};

#endif

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().sortList(head));
  return 0;
}
