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
    int rob(TreeNode* root) {
        map<pair<TreeNode*, bool>, int> rec;
        function<int(TreeNode*, bool)> F;
        F = [&](TreeNode *r, bool safe) -> int {
            if (!r) return 0;
            auto p = rec.find({r, safe});
            if (p != rec.end()) return p->second;
            int val = F(r->left, true) + F(r->right, true);
            if (safe) {
                val = max(val, F(r->left, false) + F(r->right, false) + r->val);
            }
            rec[{r, safe}] = val;
            return val;
        };
        F(root, true);
        return rec[{root, true}];
    }
};


class Solution {
public:
    int rob(TreeNode* root) {
        array<int, 2> res = dp(root); // norob, rob
        return max(res[0], res[1]);
    }
    array<int, 2> dp(TreeNode *root) {
        if (!root) return {0, 0};
        array<int, 2> left = dp(root->left);
        array<int, 2> right = dp(root->right);
        int rob = root->val + left[0] + right[0];
        int norob = max(left[0], left[1]) + max(right[0], right[1]); // NOTICE!!
        return {norob, rob};
    }
};
