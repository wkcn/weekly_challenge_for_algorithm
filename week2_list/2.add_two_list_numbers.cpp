#include "common.h"

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *res = nullptr;
    ListNode **ref = &res;
    int su = 0;
    while (l1 || l2 || su > 0) {
      if (l1) {
        su += l1->val; l1 = l1->next;
      }
      if (l2) {
        su += l2->val; l2 = l2->next;
      }
      *ref = new ListNode(su % 10);
      su /= 10;
      ref = &((*ref)->next);
    }
    return res;
  }
};
#elif SOLUTION == 2

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *res = nullptr;
    ListNode **ref = &res;
    int su = 0;
    while (l1 || l2) {
      if (l1) {
        su += l1->val; l1 = l1->next;
      }
      if (l2) {
        su += l2->val; l2 = l2->next;
      }
      *ref = new ListNode(su % 10);
      su /= 10;
      ref = &((*ref)->next);
    }
    if (su > 0) *ref = new ListNode(su);
    return res;
  }
};

#endif

int main() {
  ListNode *l1 = INPUT_LIST<ListNode>();
  ListNode *l2 = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().addTwoNumbers(l1, l2));
  return 0;
}
