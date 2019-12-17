#include "common.h"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 注意指针谁指向谁，哪个指针位置需要清空
class Solution {
public:
  void flatten(TreeNode* root) {
    // VLR
    if (!root) return;
    if (root->left) {
      flatten(root->left);
      flatten(root->right);
      TreeNode *r = root->left;
      while (r->right) r = r->right;
      r->right = root->right;
      root->right = root->left;
      root->left = nullptr;
    } else {
      flatten(root->right);
    }
  }
};

// TODO: 非递归版本

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  Solution().flatten(root);
  PRINT_BTREE_LEVEL(root);
  return 0;
}
