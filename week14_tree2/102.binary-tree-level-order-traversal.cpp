/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      if (!root) return {};
      vector<vector<int> > res;
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        while (size--) {
          TreeNode *r = q.front(); q.pop();
          level.push_back(r->val);
          if (r->left) q.push(r->left);
          if (r->right) q.push(r->right);
        }
        res.emplace_back(level);
      }
      return res;
    }
};
