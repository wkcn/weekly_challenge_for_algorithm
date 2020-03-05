#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    bool hasCycle(ListNode *head) {
      if (!head) return false; // 空链表处理!!!!!
      ListNode *slow = head, *fast = head;
      while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
          return true;
          /*
          int pos = 0;
          slow = head;
          while (slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
            ++pos;
          }
          cout << "POS: " << pos << endl;
          return pos;
          */
        }
      }
      return false;
    }
};

int main() {
  int n, u;
  cin >> n >> u;
  ListNode *head = Vector2List<ListNode>(RANGE(n));
  PRINT_LIST(head);
  ListNode *tail = head; 
  while (tail->next) tail = tail->next;
  if (u >= 0) {
    ListNode *p = head;
    for (int i = 0; i < u; ++i) p = p->next;
    tail->next = p;
  }
  cout << Solution().hasCycle(head) << endl;
  return 0;
}
