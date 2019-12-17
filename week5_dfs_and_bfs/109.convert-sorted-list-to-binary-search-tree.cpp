#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    return sortedListToBST(head, nullptr);
  }
private:
  TreeNode* sortedListToBST(ListNode *start, ListNode *end) {
    if (start == end) return nullptr;
    ListNode *slow = start, *fast = start->next;
    while (fast != end) {
      slow = slow->next;
      fast = fast->next;
      if (fast != end) fast = fast->next;
    }
    TreeNode *r = new TreeNode(slow->val);
    r->left = sortedListToBST(start, slow);
    r->right = sortedListToBST(slow->next, end);
    return r;
  }
};

// 可以使用断链法将end去掉, 但要记得恢复链表的链接

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  PRINT_BTREE_VLR(Solution().sortedListToBST(head));
  return 0;
}
