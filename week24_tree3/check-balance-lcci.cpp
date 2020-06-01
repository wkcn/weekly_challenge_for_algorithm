// 判断是否平衡，只需看高度
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
    bool isBalanced(TreeNode* root) {
        return check(root, nullptr, nullptr) != -1;
    }
    int check(TreeNode *root, TreeNode *min_root, TreeNode *max_root) {
        if (!root) return 0;
        //if (min_root && min_root->val >= root->val) return -1;
        //if (max_root && max_root->val <= root->val) return -1;
        int left = check(root->left, min_root, root);
        if (left == -1) return -1;
        int right = check(root->right, root, max_root);
        if (right == -1) return -1;
        if (abs(left-right) >= 2) return -1;
        return max(left, right) + 1;
    }
};
