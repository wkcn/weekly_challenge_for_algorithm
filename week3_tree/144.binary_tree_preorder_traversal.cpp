#include "common.h"

/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
*/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    // VLR
    if (!root) return {};
    vector<int> res;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *r = st.top(); st.pop();
      res.push_back(r->val);
      if (r->right) st.push(r->right);
      if (r->left) st.push(r->left);
    }
    return res;
  }
private:
  void push_left(TreeNode *r, stack<TreeNode*> &st) {
    while (r) {
      st.push(r);
      r = r->left;
    }
  }
};
#elif SOLUTION == 2
// Notice: Leetcode will delete tree nodes.
// If the link of tree nodes are modified, it will raise RuntimeError!!!
// Therefore, we should keep the same tree.
class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    // VLR
    if (!root) return {};
    vector<int> res;
    while (root) {
      if (root->left) {
        TreeNode *l_last = root->left;
        while (l_last->right && l_last->right != root) l_last = l_last->right;
        if (!l_last->right) {
          res.push_back(root->val);
          l_last->right = root;
          root = root->left;
        } else {
          // l_last->right is extra link we added.
          l_last->right = nullptr;
          root = root->right;
        }
      } else {
        res.push_back(root->val);
        root = root->right;
      }
    }
    return res;
  }
};
#endif

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  PRINT_ARRAY(Solution().preorderTraversal(root));
  return 0;
}
