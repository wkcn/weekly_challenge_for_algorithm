#include "common.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 注意，视图的节点可能同时在左右分支
class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};
    // RLV
    vector<int> ans;
    stack<TreeNode*> st;
    PushRight(root, st, ans);
    TreeNode *pre = nullptr;
    while (!st.empty()) {
      TreeNode *r = st.top();
      // 注意有两种情况
      if (!r->left || r->left == pre) {
        st.pop();
      } else {
        PushRight(r->left, st, ans);
      }
      pre = r;
    }
    return ans;
  }
private:
  void PushRight(TreeNode *root, stack<TreeNode*> &st, vector<int> &ans) {
    while (root) {
      st.push(root);
      if (st.size() > ans.size()) ans.push_back(root->val);
      root = root->right;
    }
  }
};
// 也可以用层次遍历或其他遍历做

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  PRINT_ARRAY(Solution().rightSideView(root));
  return 0;
}
