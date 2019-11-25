#include "common.h"

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 有很多种解法，封装下函数可能会更好，多画画简单例子是怎么连接的
class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k <= 1) return head;
    int len = 0;
    for (ListNode *p=head;p;p=p->next) ++len;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *p = &dummy;
    int g = len / k;
    while (g--) {
      ListNode *pre = p->next;
      ListNode *cur = pre->next;
      for (int i = 1; i < k; ++i) {
        ListNode *nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
      }
      p->next->next = cur;
      ListNode *nex = p->next;
      p->next = pre;
      p = nex;
    } 
    return dummy.next;
  }
};

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  int k;
  cin >> k;
  PRINT_LIST(Solution().reverseKGroup(head, k));
  return 0;
}
