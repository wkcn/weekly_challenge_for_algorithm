#include "common.h"

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#define SOLUTION 3

#if SOLUTION == 1
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;
    ListNode *p = head;
    ListNode *last = nullptr;
    while (p->next) {
      // reverse p and p->next
      // last(done) -> p -> (p->next) 
      ListNode *t = p->next;
      p->next = last;
      last = p;
      p = t;
    }
    p->next = last;
    return p;
  }
};
#elif SOLUTION == 2

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr, *cur = head;
    while (cur) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }
};

#elif SOLUTION == 3

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
  }
};

#endif

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().reverseList(head));
  return 0;
}
