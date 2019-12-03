#include "common.h"
/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
*/

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 从叶子到根节点可以用递归
#define SOLUTION 2
// 这个方法需要遍历所有节点，很慢
#if SOLUTION == 1
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    // prune 
    if (left && left != p && left != q) return left;
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    /* left, right, out
     * v   , null , v
     * null, v    , v
     * v   , v    , root
     * null, null , null
     */
    return !left ? right : (!right ? left : root);
  }
};
#elif SOLUTION == 2
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    stack<TreeNode*> st;
    // LRV
    TreeNode *pre = nullptr;
    push_left(root, st);
    // first step: find the first element
    TreeNode *r;
    while (!st.empty()) {
      r = st.top();
      if (r == p || r == q) break;
      if (!r->right || pre == r->right) {
        st.pop();
      } else {
        push_left(r->right, st);
      }
      pre = r;
    }
    if (r != p && r != q) return nullptr;
    TreeNode *need = r == p ? q : p; 
    int depth = st.size();
    while (!st.empty()) {
      r = st.top();
      if (r == need) break;
      if (!r->right || pre == r->right) {
        st.pop();
        if (st.size() < depth) depth = st.size();
      } else {
        push_left(r->right, st);
      }
      pre = r;
    }
    if (r != need) return nullptr;
    while (st.size() > depth) {
      st.pop();
    }
    return st.top();
  }
private:
  void push_left(TreeNode *p, stack<TreeNode*> &st) {
    while (p) {
      st.push(p);
      p = p->left;
    }
  }
};
#endif

TreeNode* find_node(TreeNode *root, int val) {
  if (!root) return nullptr;
  if (root->val == val) return root;
  TreeNode *left = find_node(root->left, val);
  if (left) return left;
  TreeNode *right = find_node(root->right, val);
  return right;
}

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  int p, q;
  cin >> p >> q;
  TreeNode *rp = find_node(root, p);
  TreeNode *rq = find_node(root, q);
  cout << Solution().lowestCommonAncestor(root, rp, rq)->val << endl;
  return 0;
}
