#include "common.h"

// Definition for a binary tree node.
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
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    stack<pair<TreeNode*, TreeNode*> > st;
    st.push({root->left, root->right});
    while (!st.empty()) {
      auto p = st.top(); st.pop();
      TreeNode *left = p.first;
      TreeNode *right = p.second;
      if (!left && !right) continue;
      if (!left || !right) return false;
      if (left->val != right->val) return false;
      st.push({left->left, right->right});
      st.push({left->right, right->left});
    }
    return true;
  }
};
#elif SOLUTION == 2
class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    return Helper(root, root);
  }
private:
  bool Helper(TreeNode *left, TreeNode *right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    if (left->val != right->val) return false;
    return Helper(left->left, right->right) && Helper(left->right, right->left);
  }
};

#endif

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  cout << Solution().isSymmetric(root) << endl;
  return 0;
}
