#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
      ListNode *slow = head, *fast = head;
      // 1 -> null
      // 1 -> 2 -> null
      // 1 -> 2 -> 3(s) -> 4 -> null(f)
      // 1 -> 2 -> 3(s) -> 4 -> 5(f) -> null
      // fast为nullptr或fast->next == nullptr时结束
      while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
      }
      return slow;
    }
};

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  cout << Solution().middleNode(head)->val << endl;
  return 0;
}
