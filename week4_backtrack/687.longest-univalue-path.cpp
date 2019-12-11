// 注意递归返回的是什么长度
#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  int longestUnivaluePath(TreeNode* root) {
    ma = 0;
    helper(root);
    return ma;
  }
private:
  int helper(TreeNode *root) {
    // return: leaf -> root
    if (!root) return 0;
    int l = 0, r = 0;
    int el = 0, er = 0;
    if (root->left) {
      l = helper(root->left);
      if (root->left->val == root->val) {
        el += 1 + l;
      }
    }
    if (root->right) {
      r = helper(root->right);
      if (root->right->val == root->val) {
        er += 1 + r;
      }
    }
    int e = el + er;
    if (e > ma) ma = e;
    return max(el, er);
  }
  int ma;
};
#elif SOLUTION == 2
class Solution {
public:
  int longestUnivaluePath(TreeNode* root) {
    if (!root) return 0;
    best = 0;
    helper(root, root->val);
    return best;
  }
private:
  int helper(TreeNode *root, int val) {
    if (!root) return 0;
    int l = helper(root->left, root->val);
    int r = helper(root->right, root->val);
    best = max(best, l + r);
    if (root->val == val) return max(l, r) + 1;
    return 0;
  }
  int best;
};
#endif

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  cout << Solution().longestUnivaluePath(root) << endl;
  return 0;
}
