#include "common.h"

#define SOLUTION 2

class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    int lo = 0, hi = nums.size() - 1;
    // 如果用hi = nums.size()的方法
    // 4, 1, 2, 3
    // lo = 0, hi = 4, mid = 2
    // 2 < 3, lo = 0, hi = 2, mid = 1
    // 1 == 1, lo = 2, hi = 2, return 2
    //
    // 如果使用hi = nums.size()-1的方法，
    // 4, 1, 2, 3
    // lo = 0, hi = 3, mid = 1
    // 1 < 3, lo = 0, hi = 1, mid = 0
    // 4 > 1, lo = 1, hi = 1, return 1
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      nums[mid] < nums[hi] ? hi = mid : lo = mid + 1;
    }
    int r = lo;
#if SOLUTION == 1
    // r is the position of the minimum value
    // 考虑到有序数组可能不翻转
    // 要和nums.back()比较，而不是和nums.front()比较
    if (target > nums.back()) {
      lo = 0, hi = r;
    } else {
      lo = r, hi = nums.size();
    }
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      nums[mid] < target ? lo = mid + 1 : hi = mid; 
    }
    // 三目运算符?:的优先级很低
    return lo == nums.size() || nums[lo] != target ? -1 : lo;
#elif SOLUTION == 2
    const int len = nums.size();
    lo = 0, hi = len;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      nums[(mid + r) % len] < target ? lo = mid + 1 : hi = mid; 
    }
    // 4 5 6 7 0 1 2, target=0, r=4
    // lo = 0
    // it should return 4
    // f(x) = (x + r) % n
    if (lo == len || nums[(lo + r) % len] != target) return -1; 
    return (lo + r) % len;
#endif
  }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  int target;
  cin >> target;
  cout << Solution().search(nums, target) << endl;
  return 0;
}
