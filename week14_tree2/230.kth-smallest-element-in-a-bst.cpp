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
    int kthSmallest(TreeNode* root, int k) {
      // It is not a balanced tree!
      // LVR
      stack<TreeNode*> st;
      PushLeft(st, root);
      while (!st.empty()) {
        TreeNode *r = st.top(); st.pop();
        if (--k == 0) return r->val;
        PushLeft(st, r->right);
      }
      return 0;
    }
    void PushLeft(stack<TreeNode*> &st, TreeNode *r) {
        while (r) {
            st.push(r);
            r = r->left;
        }
    }
};
