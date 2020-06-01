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
    int sumRootToLeaf(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int> > q;
        q.push({root, root->val});
        int ans = 0;
        const int MOD = 1000000007;
        while (!q.empty()) {
            auto [r, val] = q.front(); q.pop();
            if (!r->left && !r->right) {
                ans = (ans + val) % MOD;
                continue;
            }
            if (r->left) q.push({r->left, ((val << 1) + r->left->val) % MOD});
            if (r->right) q.push({r->right, ((val << 1) + r->right->val) % MOD});
        }
        return ans;
    }
};
