#include "common.h"

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int i = 0, j = nums.size();
    while (i < j) {
      int mid = i + (j - i) / 2;
      if (nums[mid] == target) return mid; // 这句可以删除
      else nums[mid] < target ? i = mid + 1 : j = mid;
    }
    // [0, i), x < target
    // [i, nums.size()), x >= target
    return i;
  }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  int target;
  cin >> target;
  cout << Solution().searchInsert(nums, target) << endl;
  return 0;
}
