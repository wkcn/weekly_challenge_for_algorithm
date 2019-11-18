#include "common.h"

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int ma = nums[0];
    int res = ma;
    int len = nums.size();
    for (int i = 1; i < len; ++i) {
      int &x = nums[i];
      ma = max(ma + x, x);
      if (ma > res) res = ma;
    }
    return res;
  }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().maxSubArray(nums) << endl;
  return 0;
}
