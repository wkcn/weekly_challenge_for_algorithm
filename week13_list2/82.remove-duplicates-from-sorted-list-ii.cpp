#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode dummy(-1);
      dummy.next = head;
      ListNode *cur = &dummy;
      // cur->next是准备处理的元素
      while (cur->next && cur->next->next) {
        if (cur->next->next->val != cur->next->val) {
          cur = cur->next;
        } else {
          ListNode *p = cur->next->next->next;
          while (p && p->val == cur->next->val) p = p->next;
          cur->next = p;
        }
      }
      return dummy.next;
    }
};

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().deleteDuplicates(head));
  return 0;
}
