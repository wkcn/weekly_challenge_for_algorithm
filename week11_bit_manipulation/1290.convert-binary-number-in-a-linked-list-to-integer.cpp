#include "common.h"
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    int getDecimalValue(ListNode* head) {
      int v = 0;
      while (head) {
        v = (v << 1) | head->val;
        head = head->next;
      }
      return v;
    }
};

int main() {
  ListNode* head = INPUT_LIST<ListNode>();
  cout << Solution().getDecimalValue(head) << endl;
  return 0;
}
