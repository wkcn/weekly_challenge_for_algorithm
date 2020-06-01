// TODO: morris
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
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        // RVL
        int su = 0;
        stack<TreeNode*> st;
        auto PushRight = [&](TreeNode *r) {
            while (r) {
                st.push(r); r = r->right;
            }
        };
        PushRight(root);
        while (!st.empty()) {
            TreeNode *r = st.top(); st.pop();
            su += r->val;
            r->val = su;
            PushRight(r->left);
        }
        return root;
    }
};
