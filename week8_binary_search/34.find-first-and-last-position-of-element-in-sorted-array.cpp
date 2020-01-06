#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
template <typename Iter, typename T>
Iter my_lower_bound(Iter begin, Iter end, T target) {
  while (begin < end) {
    Iter mid = begin + (end - begin) / 2;
    *mid < target ? begin = mid + 1 : end = mid;
  }
  return begin;
}

template <typename Iter, typename T>
Iter my_upper_bound(Iter begin, Iter end, T target) {
  while (begin < end) {
    Iter mid = begin + (end - begin) / 2;
    *mid <= target ? begin = mid + 1 : end = mid;
  }
  return --begin;
}

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1}; // 对空数组做upper_bound会数组越界
    auto lb = my_lower_bound(nums.begin(), nums.end(), target);
    // 注意，找不到的情况下有两种条件
    if (lb == nums.end() || *lb != target) return {-1, -1};
    // 以lb为左边界能够加速
    auto ub = my_upper_bound(lb, nums.end(), target);
    return {lb - nums.begin(), ub - nums.begin()};
  }
};
#elif SOLUTION == 2
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1}; // 对空数组做upper_bound会数组越界
    int lo = 0, hi = nums.size();
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      nums[mid] < target ? lo = mid + 1 : hi = mid;
    }
    if (lo == nums.size() || nums[lo] != target) return {-1, -1};
    int left = lo;
    hi = nums.size();
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      nums[mid] <= target ? lo = mid + 1 : hi = mid;
    }
    return {left, --lo};
  }
};
#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  int target;
  cin >> target;
  PRINT_ARRAY(Solution().searchRange(nums, target));
  return 0;
}
