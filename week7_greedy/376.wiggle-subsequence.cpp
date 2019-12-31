#include "common.h"

#define SOLUTION 2
#if SOLUTION == 1
// 开头数字可能相同，因此要使用first
class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    const int len = nums.size();
    // 注意空序列！
    int count = len;
    bool first = true;
    bool flag = false;
    for (int i = 0; i < len - 1; ++i) {
      int diff = nums[i+1] - nums[i];
      if (diff == 0) {
        --count;
      } else {
        bool w = diff > 0;
        if (first) {
          flag = w;
          first = false;
        } else if (w ^ flag) {
          flag = !flag;
        } else {
          --count;
        }
      }
    }
    return count;
  }
};
#elif SOLUTION == 2
// reference: https://leetcode.com/problems/wiggle-subsequence/discuss/84887/C%2B%2B-0ms-O(N)-dynamic-programming-solution
// TODO: 状态压缩
class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    const int len = nums.size();
    if (len <= 1) return len;
    vector<int> pos(len, 0), neg(len, 0);
    pos[0] = 1;
    neg[0] = 1;
    for (int i = 1; i < len; ++i) {
      if (nums[i-1] == nums[i]) {
        pos[i] = pos[i-1];
        neg[i] = neg[i-1];
      } else if (nums[i-1] < nums[i]) {
        pos[i] = pos[i-1];
        neg[i] = pos[i-1]+1; // pos[i-1] + 1 >= neg[i-1]
        // 可以举例出来证明
      } else {
        neg[i] = neg[i-1];
        pos[i] = neg[i-1]+1; // neg[i-1] + 1 >= pos[i-1]
      }
    }
    return max(neg[len-1], pos[len-1]);
  }
};

#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().wiggleMaxLength(nums) << endl;
  return 0;
}
