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
    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;
        // LVR
        stack<TreeNode*> st;
        auto PushLeft = [&](TreeNode *r) {
            while (r) {
                st.push(r); r = r->left;
            }
        };
        PushLeft(root);
        TreeNode *pre = nullptr;
        int ans = INT32_MAX;
        while (!st.empty()) {
            TreeNode *r = st.top(); st.pop();
            if (pre) ans = min(ans, abs(r->val - pre->val));
            pre = r;
            PushLeft(r->right);
        }
        return ans;
    }
};
