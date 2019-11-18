#include "common.h"

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    const int len = nums.size();
    if (len < 3) return {};
    sort(nums.begin(), nums.end());
    vector<vector<int> > res;
    vector<int> forward(len), backward(len);
    // [i, j]
    int i, j, v;
    for (v = nums[0], i = 0, j = 1; j < len; ++j) {
      if (v != nums[j]) {
        for (int z = i; z < j; ++z) forward[z] = j;
        v = nums[j];
        i = j;
      }
    }
    for (int z = i; z < j; ++z) forward[z] = j;
    // [i, j]
    for (v = nums.back(), i = len - 2, j = len - 1; i >= 0; --i) {
      if (v != nums[i]) {
        for (int z = i + 1; z <= j; ++z) backward[z] = i;
        v = nums[i];
        j = i;
      }
    }
    for (int z = i + 1; z <= j; ++z) backward[z] = i;
    for (i = 0; i < len - 2 && nums[i] <= 0; i = forward[i]) {
      int j = i + 1;
      int k = len - 1;
      while (j < k) {
        int su = nums[i] + nums[j] + nums[k];
        if (su == 0) {
          res.push_back({nums[i], nums[j], nums[k]});
          j = forward[j]; k = backward[k];
        } else {
          su < 0 ? j = forward[j] : k = backward[k];
        }
      }
    }
    return res;
  }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  auto res = Solution().threeSum(nums);
  for (auto v : res) {
    PRINT_ARRAY(v);
  }
  return 0;
}
