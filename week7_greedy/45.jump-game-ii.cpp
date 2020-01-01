#include "common.h"

#define SOLUTION 2
#if SOLUTION == 1
class Solution {
public:
  int jump(vector<int>& nums) {
    // dp[i] = min({dp[i-s]+1 if j < i and 0 < s <= nums[j]})
    const int len = nums.size();
    if (len <= 1) return 0;
    queue<pair<int, int> > q;
    q.push({nums[0], 1});
    if (q.front().first >= len - 1) return q.front().second;
    for (int i = 1; i < len; ++i) {
      while (!q.empty() && i > q.front().first) {
        q.pop();
      }
      if (q.empty()) return -1;
      int nt = i + nums[i];
      auto &p = q.front();
      if (nt > p.first) {
        if (nt >= len - 1) return p.second + 1;
        q.push({nt, p.second + 1});
      }
    }
    return -1;
  }
};
#elif SOLUTION == 2
// 分清区间
// https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy
class Solution {
public:
  int jump(vector<int>& nums) {
    const int len = nums.size();
    if (len <= 1) return 0;
    int cur_end = 0;
    int next_end = 0;
    int step = 0;
    // 使用step 可以跳到[next_end, cur_end]
    // 注意：这里是len - 1, 不用考虑最后一格
    for (int i = 0; i < len - 1; ++i) {
      next_end = max(next_end, i + nums[i]);
      if (i == cur_end) {
        cur_end = next_end;
        ++step;
      }
    }
    return step;
  }
};

#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().jump(nums) << endl;
  return 0;
}
