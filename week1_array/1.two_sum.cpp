#include "common.h"

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int len = nums.size();
    vector<int> res(2, -1);
    map<int, int> ma;
    for (int i = 0; i < len; ++i) {
      int &x = nums[i];
      if (ma.count(x)) {
        res[0] = ma[x];
        res[1] = i;
        break;
      }
      ma[target - x] = i;
    }
    return res;
  }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  int target;
  cin >> target;
  vector<int> res = Solution().twoSum(nums, target);
  cout << res[0] << ',' << res[1] << endl;
  return 0;
}
