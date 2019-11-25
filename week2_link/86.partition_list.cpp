#include "common.h"

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    ListNode *left = nullptr, *right = nullptr;
    ListNode **pleft = &left, **pright = &right;
    while (head) {
      if (head->val < x) {
        *pleft = head;
        pleft = &((*pleft)->next);
      } else {
        *pright = head;
        pright = &((*pright)->next);
      }
      head = head->next;
    }
    // notice head and tail!
    *pleft = right;
    *pright = nullptr;
    return left;
  }
};

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  int x;
  cin >> x;
  PRINT_LIST(Solution().partition(head, x));
  return 0;
}
