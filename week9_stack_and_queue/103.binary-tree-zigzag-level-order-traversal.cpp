#include "common.h"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int> > res;
    stack<TreeNode*> st[2];
    bool flag = false;
    st[flag].push(root);
    while (!st[flag].empty()) {
      vector<int> buf;
      stack<TreeNode*> &cst = st[flag];
      stack<TreeNode*> &ost = st[!flag];
      while (!cst.empty()) {
        TreeNode *r = cst.top(); cst.pop();
        buf.push_back(r->val);
        if (flag) {
          push_root(r->right, ost);
          push_root(r->left, ost);
        } else {
          push_root(r->left, ost);
          push_root(r->right, ost);
        }
      }
      flag = !flag;
      res.emplace_back(buf);
    }
    return res;
  }
private:
  void push_root(TreeNode *&r, stack<TreeNode*> &st) {
    if (r) st.push(r);
  }
};

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  for (auto &v : Solution().zigzagLevelOrder(root)) {
    PRINT_ARRAY(v);
  }
  return 0;
}
