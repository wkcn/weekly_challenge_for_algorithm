#include "common.h"

// Definition for a binary tree node.
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
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};
#elif SOLUTION == 2
class Solution {
public:
  int maxDepth(TreeNode* root) {
    stack<pair<TreeNode*, int> > st;
    int height = 0;
    st.push({root, 0});
    while (!st.empty()) {
      auto p = st.top(); st.pop();
      TreeNode *&r = p.first;
      if (r) {
        int u = p.second + 1;
        st.push({r->left, u});
        st.push({r->right, u});
      } else {
        height = max(height, p.second);
      }
    }
    return height;
  }
};
#elif SOLUTION == 3
class Solution {
public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int height = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      ++height;
      const int n = q.size();
      for (int i = 0; i < n; ++i) {
        TreeNode *r = q.front(); q.pop();
        if (r->left) q.push(r->left);
        if (r->right) q.push(r->right);
      }
    }
    return height;
  }
};
#endif

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  cout << Solution().maxDepth(root) << endl;
  return 0;
}
