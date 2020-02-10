#include "common.h"
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* insertionSortList(ListNode* head) {
    if (!head) return nullptr;
    ListNode dummy(INT32_MIN); dummy.next = head;
    ListNode *r = &dummy;
    while (r->next) {
      if (r->next->val < r->val) {
        // remove this node
        ListNode *t = r->next;
        r->next = t->next;
        // push this node into link
        ListNode *u = &dummy;
        while (u->next && u->next->val < t->val) u = u->next;
        t->next = u->next;
        u->next = t; 
      } else
        r = r->next;
    }
    return dummy.next;
  }
};

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().insertionSortList(head));
  return 0;
}
