#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // VLR
    // LVR
    return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
  }
private:
  TreeNode* buildTree(vector<int> &VLR, int i, int j, vector<int> &LVR, int m, int n) {
    if (j - i <= 0) return nullptr;
    int v = VLR[i];
    int k = m;
    for (; k < n && LVR[k] != v; ++k);
    TreeNode *r = new TreeNode(v);
    const int nleft = k - m;
    r->left = buildTree(VLR, i + 1, i + 1 + nleft, LVR, m, k);
    r->right = buildTree(VLR, i + 1 + nleft, j, LVR, k + 1, n);
    return r;
  } 
};

// TODO: Iterative Solution
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34555/The-iterative-solution-is-easier-than-you-think!

int main() {
  vector<int> preorder, inorder;
  INPUT_ARRAY(preorder);
  INPUT_ARRAY(inorder);
  TreeNode *r = Solution().buildTree(preorder, inorder);
  PRINT_BTREE_VLR(r);
  return 0;
}
