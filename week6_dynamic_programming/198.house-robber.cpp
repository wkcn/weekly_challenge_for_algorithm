#include "common.h"

class Solution {
public:
  int rob(vector<int>& nums) {
    int rob_num = 0, norob_num = 0;
    for (int x : nums) {
      const int r = norob_num + x;
      // 可能上一次norob的值比当前rob_num还大
      if (rob_num > norob_num) norob_num = rob_num;
      rob_num = r; 
    }
    // 可以在状态结束时再找最大值，不需要每次都在循环中找
    return max(rob_num, norob_num);
  }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().rob(nums) << endl;
  return 0;
}
