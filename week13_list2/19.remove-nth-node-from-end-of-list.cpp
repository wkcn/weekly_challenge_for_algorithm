#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode dummy(-1);
      dummy.next = head;
      ListNode *back = &dummy, *front = &dummy;
      for (int i = 0; i < n; ++i) front = front->next;
      // dummy -> 1 -> 2 -> 3(b) -> 4(remove) -> 5(f) -> null
      while (front->next) {
        back = back->next;
        front = front->next;
      }
      back->next = back->next->next;
      return dummy.next;
    }
};

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  int n; cin >> n;
  PRINT_LIST(Solution().removeNthFromEnd(head, n));
  return 0;
}
