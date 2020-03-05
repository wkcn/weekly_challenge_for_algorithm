#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if (!head) return nullptr;
      ListNode dummy(-1);
      dummy.next = head;
      ListNode *cur = &dummy;
      while (cur->next && cur->next->next) {
        // swap cur->next and cur->next->next
        ListNode *left = cur->next;
        cur->next = left->next; // right
        left->next = cur->next->next;
        cur->next->next = left;
        cur = left;
      }
      return dummy.next;
    }
};

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().swapPairs(head));
  return 0;
}
