#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      ListNode dummy(INT_MIN);
      dummy.next = head;
      ListNode *cur = head;
      ListNode *last = &dummy;
      while (cur) {
        if (cur->val >= last->val) {
          last = cur;
          cur = cur->next;
        } else {
          last->next = cur->next;
          ListNode *p = &dummy;
          while (p->next && cur->val > p->next->val) p = p->next;
          cur->next = p->next;
          p->next = cur;
          cur = last->next;
        }
      }
      return dummy.next;
    }
};

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().insertionSortList(head));
  return 0;
}
