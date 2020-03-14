/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      // inorder: LVR
      // postorder: LRV
      unordered_map<int, int> inorder_map;
      for (int i = 0; i < inorder.size(); ++i) inorder_map[inorder[i]] = i;
      return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size(), inorder_map);
    }
    TreeNode* buildTree(vector<int>& inorder, int ibegin, int iend, vector<int>& postorder, int pbegin, int pend, const unordered_map<int, int>& inorder_map) {
      if (ibegin >= iend) return nullptr;
      int v = postorder[pend-1];
      // int i; for (i = ibegin; i < iend && inorder[i] != v; ++i);
      int i = inorder_map.at(v);
      TreeNode *r = new TreeNode(v);
      int left = i - ibegin;
      r->left = buildTree(inorder, ibegin, i, postorder, pbegin, pbegin + left, inorder_map);
      r->right = buildTree(inorder, i+1, iend, postorder, pbegin + left, pend-1, inorder_map);
      return r;
    }
};
#elif SOLUTION == 2

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/34807/Java-iterative-solution-with-explanation
// [TODO] 递归版本
/*
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      // inorder: LVR -> (LVR)V(LVR)
      // postorder: LRV -> (LRV)(LRV)V
      if (inorder.empty()) return nullptr;
      int ii = inorder.size() - 1;
      int pi = postorder.size() - 1;
      stack<TreeNode*> st;
      TreeNode *pre;
      st.push(new TreeNode[postorder[pi--]]);
      while (pi >= 0) {
        while (!st.empty() && st.top()->val == inorder[ii]) {
          pre = st.top(); st.pop();
        }
      }
    }
};
*/
#endif
