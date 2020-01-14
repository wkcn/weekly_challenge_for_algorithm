#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 平均时间复杂度O(1) ?????
class BSTIterator {
public:
  BSTIterator(TreeNode* root) {
    push_left(root);
  }

  /** @return the next smallest number */
  int next() {
    TreeNode *r = st.top(); st.pop();
    push_left(r->right);
    return r->val;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !st.empty();
  }
private:
  void push_left(TreeNode *root) {
    while (root) {
      st.push(root);
      root = root->left;
    }
  }
private:
  stack<TreeNode*> st;
};

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>(); // 7 7 3 15 0 0 9 20
  BSTIterator iterator(root);
  cout << iterator.next() << endl;    // return 3
  cout << iterator.next() << endl;    // return 7
  cout << iterator.hasNext() << endl; // return true
  cout << iterator.next() << endl;    // return 9
  cout << iterator.hasNext() << endl; // return true
  cout << iterator.next() << endl;    // return 15
  cout << iterator.hasNext() << endl; // return true
  cout << iterator.next() << endl;    // return 20
  cout << iterator.hasNext() << endl; // return false
  return 0;
}
