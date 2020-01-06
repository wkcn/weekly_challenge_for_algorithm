#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
// 这种方法适合找上下界
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int i = 0, j = nums.size();
    while (i < j) {
      int mid = i + (j - i) / 2;
      nums[mid] < target ? i = mid + 1 : j = mid;
    }
    return (i == nums.size() || nums[i] != target) ? -1 : i;
  }
};
#elif SOLUTION == 2
// 这种方法适合如果元素不存在时，返回-1 
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int i = 0, j = nums.size();
    while (i < j) {
      int mid = i + (j - i) / 2;
      if (nums[mid] == target) return mid;
      else nums[mid] < target ? i = mid + 1 : j = mid;
    }
    return -1;
  }
};
#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  int target;
  cin >> target;
  cout << Solution().search(nums, target) << endl;
  return 0;
}
