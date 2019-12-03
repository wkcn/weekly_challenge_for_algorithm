#include "common.h"

/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
*/

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
  vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    stack<TreeNode*> st;
    push_left(root, st);
    TreeNode *pre = nullptr;
    while (!st.empty()) {
      TreeNode *r = st.top();
      if (!r->right || r->right == pre) {
        res.push_back(r->val);
        pre = r;
        st.pop();
      } else {
        push_left(r->right, st);
      }
    }
    return res;
  }
private:
  void push_left(TreeNode *r, stack<TreeNode*> &st) {
    while (r) {
      st.push(r);
      r = r->left;
    }
  }
};
#elif SOLUTION == 2

// 要小心还原树，知道创建了哪些链接，要全部删掉
class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    // LRV
    TreeNode dummy(-1);
    dummy.left = root;
    root = &dummy; 
    vector<int> res;
    while (root) {
      if (root->left) {
        TreeNode *l_last = root->left;
        while (l_last->right && l_last->right != root) l_last = l_last->right;
        if (l_last->right) {
          TreeNode *last = reverse_nodes(root->left, root);
          root->left->right = nullptr;
          TreeNode *p = last;
          while (p) {
            res.push_back(p->val);
            p = p->right;
          }
          reverse_nodes(last, nullptr);
          last->right = nullptr;
          root = root->right;
        } else {
          l_last->right = root;
          root = root->left;
        }
      } else {
        root = root->right;
      }
    }
    return res;
  }
private:
  TreeNode* reverse_nodes(TreeNode *begin, TreeNode *end) {
    TreeNode *last = begin;
    TreeNode *p = begin->right;
    while (p != end) {
      TreeNode *tmp = p->right;
      p->right = last;
      last = p;
      p = tmp;
    }
    return last;
  }
};

#endif

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  PRINT_ARRAY(Solution().postorderTraversal(root));
  return 0;
}
