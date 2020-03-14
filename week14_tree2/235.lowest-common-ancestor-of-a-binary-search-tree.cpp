#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* GetNode(TreeNode *root, int val) {
  if (!root) return nullptr;
  if (root->val == val) return root;
  return val < root->val ? GetNode(root->left, val) : GetNode(root->right, val);
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      /*
       * 树为二叉搜索树
       * 有多种情况：
       * 1. p(q)是q(p)的祖先，则返回p(q)
       * 2. p和q分别是r节点不同侧的子树
       * 找最低公共祖先
       * 当发现p或q与当前节点相等，或者p和q在两侧时，就返回当前节点
       * [NOTICE] 减法比较是三态的，比用<>的二态要好
       */
      if (!root) return nullptr;
      while (root) {
        if (root == p || root == q) return root;
        bool pf = p->val < root->val;
        bool qf = q->val < root->val;
        if (pf ^ qf) return root;
        root = pf ? root->left : root->right;
      }
      return nullptr;
    }
};

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  int pv, qv;
  cin >> pv >> qv;
  TreeNode *p = GetNode(root, pv);
  TreeNode *q = GetNode(root, qv);
  cout << Solution().lowestCommonAncestor(root, p, q)->val << endl;
  return 0;
}
