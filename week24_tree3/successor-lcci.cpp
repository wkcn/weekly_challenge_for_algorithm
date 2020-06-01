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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right) {
            p = p->right;
            while (p->left) {
                p = p->left;
            }
            return p;
        }
        TreeNode *r = root;
        TreeNode *pre = nullptr;
        while (r) {
            if (p->val < r->val) {
                pre = r;
                r = r->left;
            } else {
                // p->val > r->val || p->val == r->val
                r = r->right;   
            }
        }
        return pre;
    }
};
