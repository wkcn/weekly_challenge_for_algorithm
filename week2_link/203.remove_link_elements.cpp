#include "common.h"

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy_head(-1);
    ListNode *rhead = &dummy_head;
    rhead->next = head;
    ListNode *p = rhead;
    while (p->next) {
      if (p->next->val == val) {
        // we couldn't delete the memory of p->next
        // since we don't know how the memory allocates
        p->next = p->next->next;
      } else {
        p = p->next;
      }
    }
    return rhead->next;
  }
};

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  int val;
  cin >> val;
  PRINT_LIST(Solution().removeElements(head, val));
  return 0;
}
