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
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, array<int, 2> > > q;
        q.push({root, {root->val, root->val}});
        int ans = 0;
        while (!q.empty()) {
            auto [r, mia] = q.front(); q.pop();
            int mi = mia[0], ma = mia[1];
            ans = max({ans, abs(mi - r->val), abs(ma - r->val)});
            mi = min(r->val, mi);
            ma = max(r->val, ma);
            if (r->left) q.push({r->left, {mi, ma}});
            if (r->right) q.push({r->right, {mi, ma}});
        }
        return ans;
    }
};
