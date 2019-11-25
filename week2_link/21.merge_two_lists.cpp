#include "common.h"

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *head = nullptr;
    ListNode **ref = &head;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        *ref = l1; l1 = l1->next;
      } else {
        *ref = l2; l2 = l2->next;
      }
      ref = &((*ref)->next);
    }
    if (l1) *ref = l1;
    else if (l2) *ref = l2;
    return head;
  }
};

int main() {
  ListNode *l1 = INPUT_LIST<ListNode>();
  ListNode *l2 = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().mergeTwoLists(l1, l2));
  return 0;
}
