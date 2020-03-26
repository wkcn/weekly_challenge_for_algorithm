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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            // size > 0
            int ma = q.front()->val;
            while (size--) {
                TreeNode *r = q.front(); q.pop();
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
                ma = max(r->val, ma);
            }
            ans.push_back(ma);
        }
        return ans;
    }
};
