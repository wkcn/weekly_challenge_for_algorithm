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
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while (!q.empty()) {
            int size = q.size();
            // size > 0
            ans = q.front()->val;
            while (size--) {
                TreeNode *r = q.front(); q.pop();
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
        }
        return ans;
    }
};
