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
    int minDepth(TreeNode* root) {
      if (!root) return 0;
      // find leave
      // 层次遍历
      queue<TreeNode*> q;
      q.push(root);
      int depth = 1;
      while (!q.empty()) {
        int size = q.size();
        while (size--) {
          TreeNode* r = q.front(); q.pop();
          if (!r->left && !r->right) return depth;
          if (r->left) q.push(r->left);
          if (r->right) q.push(r->right);
        }
        ++depth;
      }
      return 0;
    }
};

#elif SOLUTION == 2

class Solution {
public:
    int minDepth(TreeNode* root) {
      if (!root) return 0;
      if (!root->left && !root->right) return 1;
      if (!root->left) return minDepth(root->right) + 1;
      if (!root->right) return minDepth(root->left) + 1;
      return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

#endif
