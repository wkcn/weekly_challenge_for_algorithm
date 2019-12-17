#include "common.h"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return Helper(nums, 0, nums.size());
  }
private:
  TreeNode* Helper(vector<int> &nums, int start, int end) {
    if (end - start <= 0) return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = Helper(nums, start, mid);
    root->right = Helper(nums,mid + 1, end);
    return root;
  }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  PRINT_BTREE_LEVEL(Solution().sortedArrayToBST(nums));
  return 0;
}
