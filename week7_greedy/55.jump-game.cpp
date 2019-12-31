#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  bool canJump(vector<int>& nums) {
    const int len = nums.size();
    if (len <= 1) return true;
    int ma = 0;
    // ma < len - 1用于提前终止
    for (int i = 0; i < len && ma < len - 1; ++i) {
      if (i > ma) return false;
      ma = max(ma, i + nums[i]);
    }
    return true;
  }
};
#elif SOLUTION == 2
class Solution {
public:
  bool canJump(vector<int>& nums) {
    const int len = nums.size();
    int i = 0;
    int reach = 0;
    for (i = 0; i <= reach && i < len; ++i) {
      reach = max(reach, i + nums[i]);
    }
    return i == len;
  }
};

#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().canJump(nums) << endl;
  return 0;
}
