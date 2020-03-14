#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
      return isValidBST(root, nullptr, nullptr);
    }
    bool isValidBST(TreeNode* root, TreeNode* min_value, TreeNode* max_value) {
      if (!root) return true;
      if ((min_value && root->val <= min_value->val) || (max_value && root->val >= max_value->val)) return false;
      return isValidBST(root->left, min_value, root) &&
          isValidBST(root->right, root, max_value);
    }
};
