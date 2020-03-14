#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define SOLUTION 2

#if SOLUTION == 1
// 1, 2, 3, 4, 5, 6, 7
// 1, |3|, |2|, 4, 5, 6, 7
// 1, |5|, 3, 4, |2|, 6, 7
// 当前节点与上一个节点比较，判断是否是逆序对
// 有两种情况
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr;
        TreeNode *pre = nullptr;
        Inner(root, pre, first, second);
        swap(first->val, second->val);
    }
    void Inner(TreeNode *root, TreeNode *&pre, TreeNode *&first, TreeNode *&second) {
        // return the node whose value is largest in the subtree
        if (!root) return;
        Inner(root->left, pre, first, second);
        // do some thing
        if (pre && pre->val > root->val) {
            if (first) {
                second = root;
            } else {
                first = pre;
                second = root;
            }
        }
        pre = root;
        Inner(root->right, pre, first, second);
    }
};
#elif SOLUTION == 2

// 空间复杂度O(1)
class Solution {
public:
    void recoverTree(TreeNode* root) {
      // LVR
      TreeNode *last = nullptr;
      TreeNode *first = nullptr, *second = nullptr;
      while (root) {
        TreeNode *cur = nullptr;
        if (root->left) {
          TreeNode *l_last = root->left;
          while (l_last->right && l_last->right != root) l_last = l_last->right;
          if (!l_last->right) {
            l_last->right = root;
            root = root->left;
          } else {
            // process
            cur = root;
            l_last->right = nullptr;
            root = root->right;
          }
        } else {
          // process
          cur = root;
          root = root->right;
        }
        if (cur) {
          if (last && last->val > cur->val) {
            if (first) {
                second = cur;
            } else {
                first = last;
                second = cur;
            }
          }
          last = cur;
        }
      }
      swap(first->val, second->val);
    }
};

#endif

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  Solution().recoverTree(root);
  PRINT_BTREE_LEVEL(root);
  return 0;
}
