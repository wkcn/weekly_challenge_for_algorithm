#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> rec;
    for (const int &x : nums) {
      auto p = lower_bound(rec.begin(), rec.end(), x);
      if (p == rec.end()) {
        rec.push_back(x);
      } else {
        *p = x;
      }
    }
    return rec.size();
  }
};
#elif SOLUTION == 2
// 用过的数字存放的位置可以存新的数据
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    auto end = nums.begin();
    for (const int &x : nums) {
      auto it = lower_bound(nums.begin(), end, x);
      *it = x;
      if (it == end) {
        ++end;
      }
    }
    return end - nums.begin();
  }
};
#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().lengthOfLIS(nums) << endl;
  return 0;
}
