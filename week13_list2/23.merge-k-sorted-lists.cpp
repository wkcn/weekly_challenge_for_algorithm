#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct ListNodeCMP {
  bool operator()(ListNode *&a, ListNode *&b) const {
    return a->val > b->val;
  }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode *head = nullptr;
      ListNode **fill = &head;
      priority_queue<ListNode*, vector<ListNode*>, ListNodeCMP> q;
      for (ListNode *p : lists) {
        if (p) {
          q.push(p);
        }
      }
      while (!q.empty()) {
        ListNode *p = q.top(); q.pop();
        *fill = p;
        fill = &((*fill)->next);
        if (p->next) q.push(p->next);
      }
      *fill = nullptr;
      return head;
    }
};

int main() {
  int n;
  cin >> n;
  vector<ListNode*> lists;
  for (int i = 0; i < n; ++i) {
    ListNode *p = INPUT_LIST<ListNode>();
    lists.push_back(p);
  }
  PRINT_LIST(Solution().mergeKLists(lists));
  return 0;
}
