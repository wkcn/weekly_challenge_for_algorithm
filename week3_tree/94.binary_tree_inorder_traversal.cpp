#include "common.h"
/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
*/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define SOLUTION 3

#if SOLUTION == 1
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    LVR(root, res);
    return res;
  }
private:
  void LVR(TreeNode *root, vector<int> &res) {
    if (!root) return;
    LVR(root->left, res);
    res.push_back(root->val);
    LVR(root->right, res);
  }
};
#elif SOLUTION == 2
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    stack<TreeNode*> st;
    push_left(root, st);
    while (!st.empty()) {
      TreeNode *r = st.top(); st.pop();
      res.push_back(r->val);
      push_left(r->right, st);
    }
    return res;
  }
private:
  void push_left(TreeNode *p, stack<TreeNode*> &st) {
    while (p) {
      st.push(p);
      p = p->left;
    }
  }
};
#elif SOLUTION == 3
// Morris traversal
// reference: https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
// https://leetcode.com/problems/binary-tree-inorder-traversal/solution/
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    while (root) {
      if (root->left) {
        TreeNode *pre = root->left;
        // 可以进一步优化，取消掉pre->right != root的判断
        while (pre->right && pre->right != root) pre = pre->right;
        if (!pre->right) {
          pre->right = root;
          // root只需要走一步，因为链接还没有全部建立起来
          root = root->left;
          continue;
        } else pre->right = nullptr;
      }
      res.push_back(root->val);
      root = root->right;
    }
    return res;
  }
};
#endif
int main() {
  TreeNode *root = INPUT_BTREE_VLR<TreeNode>();
  PRINT_ARRAY(Solution().inorderTraversal(root));
  return 0;
}
