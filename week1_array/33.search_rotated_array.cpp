#include "common.h"

// reference:
// https://leetcode.wang/leetCode-33-Search-in-Rotated-Sorted-Array.html
// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14425/Concise-O(log-N)-Binary-search-solution
class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    const int len = nums.size();
    int lo = 0, hi = len - 1;
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      nums[mid] < nums[hi] ? hi = mid : lo = mid + 1;
    }
    int r = lo; // the position of minimum
    if (target > nums.back()) {
      lo = 0, hi = r;
    } else {
      lo = r, hi = len;
    }
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      nums[mid] < target ? lo = mid + 1 : hi = mid;
    }
    return (lo >= len || nums[lo] != target) ? -1 : lo;
  }
};

int main() {
  vector<int> nums;
  int target;
  INPUT_ARRAY(nums);
  cin >> target;
  cout << Solution().search(nums, target) << endl;
  return 0;
}
