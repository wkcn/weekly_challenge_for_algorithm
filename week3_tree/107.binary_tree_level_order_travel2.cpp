#include "common.h"
/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
 
// 尽可能减少重复语句
class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root) return {};
    vector<vector<int> > res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      const int n = q.size();
      vector<int> g(n);
      for (int i = 0; i < n; ++i) {
        TreeNode *r = q.front(); q.pop();
        g[i] = r->val; 
        if (r->left) q.push(r->left);
        if (r->right) q.push(r->right);
      }
      res.emplace_back(g);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  for (vector<int> &v : Solution().levelOrderBottom(root)) {
    PRINT_ARRAY(v);
  }
  return 0;
}
