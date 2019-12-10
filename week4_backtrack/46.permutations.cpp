#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int> > res;
    vector<bool> vis(nums.size(), false);
    vector<int> buf(nums.size());
    go(0, buf, vis, nums, res);
    return res;
  }
private:
  void go(int p, vector<int> &buf, vector<bool> &vis, const vector<int> &nums, vector<vector<int> > &res) {
    if (p >= buf.size()) {
      res.push_back(buf);
      return;
    }
    for (int i = 0; i < vis.size(); ++i) {
      if (!vis[i]) {
        vis[i] = true;
        buf[p] = nums[i]; 
        go(p+1, buf, vis, nums, res);
        vis[i] = false;
      }
    }
  }
};
#elif SOLUTION == 2
class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int> > res;
    sort(nums.begin(), nums.end());
    const int len = nums.size();
    while (1) {
      res.push_back(nums);
      // next permutation
      int i;
      // 注意顺序
      for (i = len - 2; i >= 0 && nums[i] >= nums[i+1]; --i) {}
      if (i < 0) break;
      auto it = lower_bound(nums.begin()+i+1, nums.end(), nums[i], greater<int>()) - 1;
      swap(nums[i], *it);
      reverse(nums.begin()+i+1, nums.end());
    }
    return res;
  }
};
#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  for (auto v : Solution().permute(nums)) {
    PRINT_ARRAY(v);
  }
  return 0;
}
