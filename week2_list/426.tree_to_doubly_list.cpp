// https://www.lintcode.com/problem/convert-binary-search-tree-to-sorted-doubly-linked-list/description
#include "common.h"

// Definition of TreeNode:
class TreeNode {
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = NULL;
  }
};

class Solution {
public:
  /**
  * @param root: root of a tree
  * @return: head node of a doubly linked list
  */
  TreeNode * treeToDoublyList(TreeNode * root) {
    if (!root) return nullptr;
    stack<TreeNode*> st;
    PushLeft(root, st);
    TreeNode *fst = st.top();
    TreeNode *pre = nullptr;
    TreeNode *r;
    while (!st.empty()) {
      r = st.top(); st.pop();
      r->left = pre;
      if (pre)
        pre->right = r;
      pre = r;
      if (r->right) PushLeft(r->right, st);
    }
    fst->left = r;
    r->right = fst;
    return fst;
  }
  void PushLeft(TreeNode *p, stack<TreeNode*> &st) {
    while (p) {
      st.push(p);
      p = p->left;
    }
  }
};

void PrintNodes(TreeNode *r, std::function<TreeNode*(TreeNode*)> func) {
  TreeNode *p = r;
  do {
    cout << p->val << ", ";
    p = func(p);
  } while (p != r);
  cout << endl;
}

int main() {
  TreeNode *r = INPUT_BTREE_LEVEL<TreeNode>();
  TreeNode *ans = Solution().treeToDoublyList(r);
  cout << "left" << endl;
  PrintNodes(ans, [](TreeNode *r) {return r->left;});
  cout << "right" << endl;
  PrintNodes(ans, [](TreeNode *r) {return r->right;});
  return 0;
}
