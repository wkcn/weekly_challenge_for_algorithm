#include "common.h"
/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
*/

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int maxPathSum(TreeNode* root) {
    if (!root) return 0;
    max_sum = root->val;
    goPath(root);
    return max_sum;
  }
private:
  int goPath(TreeNode *root) {
    // 经过root的最大值 
    int left = root->left ? max(goPath(root->left), 0) : 0;
    int right = root->right ? max(goPath(root->right), 0) : 0;
    int single_su = max(left, right) + root->val;
    int conn_su = left + right + root->val;
    if (conn_su > max_sum) max_sum = conn_su;
    return single_su;
  }
  int max_sum;
};

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  cout << Solution().maxPathSum(root) << endl;
  return 0;
}
