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
    TreeNode* recoverFromPreorder(string S) {
        TreeNode *root = nullptr;
        stack<pair<TreeNode**, int> > st;
        st.push({&root, 0});
        const int len = S.size();
        int i = 0;
        while (i < len) {
            int d = 0;
            while (i < len && S[i] == '-') {
                ++d; ++i;
            }
            int v = 0;
            while (i < len && isdigit(S[i])) {
                v = v * 10 + (S[i] - '0');
                ++i;
            }
            while (st.top().second != d) st.pop();
            TreeNode **r = st.top().first; st.pop();
            *r = new TreeNode(v);
            st.push({&((*r)->right), d + 1});
            st.push({&((*r)->left), d + 1});
        }
        return root;
    }
};
