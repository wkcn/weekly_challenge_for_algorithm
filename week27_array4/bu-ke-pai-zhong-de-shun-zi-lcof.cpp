#include "common.h"

// 也可以只找到最小值，如果最小值+ 5 - 1 > 13, 则将最小值设为9
// 忽略0, 只找最大值最小值，然后判断max_value - min_value < 5即可
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        // 先确定最大值和最小值，剩下的可以用0补上
        int min_value = 14;
        int max_value = 0;
        array<bool, 14> exists{false};
        int zero = 0;
        for (int &x : nums) {
            if (x == 0) ++zero;
            else {
                exists[x] = true;
                min_value = min(min_value, x);
                max_value = max(max_value, x);
            }
        }
        for (int i = min_value + 1; i <= max_value - 1; ++i) {
          if (!exists[i]) {
            if (zero-- == 0) return false;
          }
        }
        return max_value - min_value + 1 + zero >= 5;
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().isStraight(nums) << endl;
  return 0;
}
