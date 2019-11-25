#include "common.h"

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) break;
    }
    if (!fast || !fast->next) return nullptr;
    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return fast;
  }
};

int main() {
  int n;
  cin >> n;
  vector<ListNode*> ps;
  for (int i = 0; i < n; ++i) ps.push_back(new ListNode{i});
  for (int i = 0; i < n - 1; ++i) ps[i]->next = ps[i+1];
  int k;
  cin >> k;
  if (k >= 0)
    ps.back()->next = ps[k];
  ListNode *r = Solution().detectCycle(ps[0]);
  if (r) cout << r->val << endl;
  else cout << "no cycle" << endl;
  return 0;
}
