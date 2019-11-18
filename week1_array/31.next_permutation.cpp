#include "common.h"

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    if (nums.empty()) return;
    const int len = nums.size();
    int p = len - 2;
    for (; p >= 0 && nums[p] >= nums[p+1]; --p) {} 
    if (p < 0) {
      reverse(nums.begin(), nums.end());
      return;
    }
    // nums[p] > nums[p+1]
    auto tend = nums.rbegin() + (len - p - 1);
    auto t = upper_bound(nums.rbegin(), tend, nums[p]); 
    swap(*t, nums[p]);
    reverse(nums.rbegin(), tend);
  }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  Solution().nextPermutation(nums);
  PRINT_ARRAY(nums);
  return 0;
}
