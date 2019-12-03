#include "common.h"
/*
invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    stack<pair<TreeNode*, TreeNode**> > st;
    TreeNode *new_root = nullptr;
    st.push({root, &new_root});
    while (!st.empty()) {
      auto p = st.top(); st.pop();
      TreeNode *&r = p.first;
      TreeNode **&t = p.second;
      *t = new TreeNode(r->val);
      if (r->left) st.push({r->left, &((*t)->right)}); 
      if (r->right) st.push({r->right, &((*t)->left)}); 
    }
    return new_root;
  }
};

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  TreeNode *ans = Solution().invertTree(root);
  PRINT_BTREE_LEVEL(ans);
  return 0;
}
