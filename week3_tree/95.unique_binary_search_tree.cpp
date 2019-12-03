#include "common.h"
/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

// Definition for a binary tree node.
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
  vector<TreeNode*> generateTrees(int n) {
    // check empty!!!!
    if (n <= 0) return {};
    vector<TreeNode*> tmp = generateTrees(1, n + 1);
    vector<TreeNode*> res;
    for (TreeNode *r : tmp) res.push_back(clone(r));
    // delete tmp node
    // Notice How to delete node!!!
    set<TreeNode*> se;
    stack<TreeNode*> st;
    for (TreeNode *r : tmp) st.push(r);
    while (!st.empty()) {
      TreeNode *r = st.top(); st.pop();
      if (se.count(r)) continue;
      se.insert(r);
      if (r->left) st.push(r->left);
      if (r->right) st.push(r->right);
      delete r;
    }
    return res;
  }
  vector<TreeNode*> generateTrees(int start, int end) {
    if (start >= end) return {nullptr};
    vector<TreeNode*> res;
    for (int i = start; i < end; ++i) {
      vector<TreeNode*> lefts = generateTrees(start, i);
      vector<TreeNode*> rights = generateTrees(i + 1, end);
      for (TreeNode *left : lefts) {
        for (TreeNode *right : rights) {
          TreeNode *root = new TreeNode(i);
          root->left = left;
          root->right = right;
          res.push_back(root);
        }
      }
    }
    return res;
  }
private:
  TreeNode* clone(TreeNode *r) {
    if (!r) return nullptr;
    TreeNode *new_r = new TreeNode(r->val);
    new_r->left = clone(r->left);
    new_r->right = clone(r->right);
    return new_r;
  }
};
#elif SOLUTION == 2

class Solution {
public:
  vector<TreeNode*> generateTrees(int n) {
    if (n <= 0) return {};
    vector<TreeNode*> res{new TreeNode(1)};
    for (int i = 2; i <= n; ++i) {
      vector<TreeNode*> tmp;
      for (TreeNode *root : res) {
        TreeNode *r = new TreeNode(i);
        TreeNode *p = root;
        while (p) {
          TreeNode *right = p->right;
          p->right = r;
          r->left = right;
          tmp.push_back(clone(root));

          p->right = right;
          p = right;
        }
        r->left = root;
        tmp.push_back(r);
      }
      res = tmp;
    }
    return res;
  }
private:
  TreeNode* clone(TreeNode *r) {
    if (!r) return nullptr;
    TreeNode *new_r = new TreeNode(r->val);
    new_r->left = clone(r->left);
    new_r->right = clone(r->right);
    return new_r;
  }
};

#endif

int main() {
  int n;
  cin >> n;
  vector<TreeNode*> res = Solution().generateTrees(n);
  for (TreeNode *r : res) {
    PRINT_BTREE_LEVEL(r);
  }
  return 0;
}
