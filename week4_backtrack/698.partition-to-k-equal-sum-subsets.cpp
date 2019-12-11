// 这道题适合算时间、空间复杂度
#include "common.h"

#define SOLUTION 3

#if SOLUTION == 1
// Approach #1: Search by Constructing Subset Sums [Accepted]
class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    if (nums.empty()) return k == 0;
    int su = 0;
    for (const int &v : nums) su += v;
    if (su % k) return false;
    int target = su / k;
    sort(nums.begin(), nums.end());
    if (nums.back() > target) return false;
    while (!nums.empty() && nums.back() == target) {
      --k;
      nums.pop_back();
    }
    if (k == 0) return true;
    vector<int> groups(k, 0);
    return helper(nums.size() - 1, nums, groups, target);
  }
private:
  bool helper(int r, const vector<int> &nums, vector<int> &groups, const int target) {
    if (r < 0) return true;
    int v = nums[r];
    const int glen = groups.size();
    for (int i = 0; i < glen; ++i) {
      if (groups[i] + v <= target) {
        groups[i] += v;
        if (helper(r - 1, nums, groups, target)) return true;
        groups[i] -= v;
      }
    }
    return false;
  }
};
#elif SOLUTION == 2
class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    if (nums.empty()) return k == 0;
    sort(nums.begin(), nums.end(), greater<int>());
    int su = 0;
    for (const int &v : nums) su += v;
    if (su % k) return false;
    target = su / k;
    vector<bool> used(nums.size(), false);
    return canPartition(nums, 0, k, target, used); 
  }
private:
  bool canPartition(vector<int> &nums, int idx, int k, int remain, vector<bool> &used) {
    if (k == 1) return true;
    const int len = nums.size();
    for (int i = idx; i < len; ++i) {
      if (used[i]) continue;
      const int &v = nums[i];
      if (remain < v) continue;
      used[i] = true;
      if (remain == v) {
        if (canPartition(nums, 0, k-1, target, used)) return true;
      } else {
        // 注意这里是i，不是idx
        if (canPartition(nums, i+1, k, remain - v, used)) return true;
      }
      used[i] = false;
    }
    return false;
  }
private:
  int target;
};
#elif SOLUTION == 3
  // TODO: 动态编程
  // https://leetcode.com/problems/partition-to-k-equal-sum-subsets/solution/
#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  int k;
  cin >> k;
  cout << Solution().canPartitionKSubsets(nums, k) << endl;
  return 0;
}
