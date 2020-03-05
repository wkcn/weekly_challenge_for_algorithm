#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if (!head) return nullptr; // 处理空链表！！！
      int len = 0;
      ListNode dummy(-1);
      dummy.next = head;
      ListNode *tail = &dummy;
      while (tail->next) {
        tail = tail->next;
        ++len;
      }
      k %= len;
      ListNode *u = &dummy;
      for (int i = 0; i < len - k; ++i, u=u->next);
      tail->next = dummy.next;
      dummy.next = u->next;
      u->next = nullptr;
      return dummy.next;
    }
};

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  int k;
  cin >> k;
  PRINT_LIST(Solution().rotateRight(head, k));
  return 0;
}
