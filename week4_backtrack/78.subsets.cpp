#include "common.h"

#define SOLUTION 4
#if SOLUTION == 1
class Solution {
public:
  Solution() {
    for (int i = 0; i < 32; ++i) {
      int t = 1 << i;
      pos1[t] = i;
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    const int len = nums.size();
    if (len <= 0) return {};
    vector<pair<int, int> > num_of_1s;
    int kind = pow(2, len);
    for (int i = 0; i < kind; ++i) {
      num_of_1s.push_back({get_num_of_1s(i), i});
    }
    sort(num_of_1s.begin(), num_of_1s.end());
    vector<vector<int> > res(kind);
    res[0] = {};
    for (int i = 1; i < kind; ++i) {
      int t = i & (i - 1);
      int p = pos1[t ^ i];
      vector<int> r = res[t];
      r.push_back(nums[p]);
      res[i] = std::move(r); 
    }
    return res;
  }
private:
  int get_num_of_1s(int n) {
    int c = 0;
    while (n > 0) {
      n &= n - 1;
      ++c;
    }
    return c;
  }
  map<int, int> pos1;
};
#elif SOLUTION == 2
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int> > res;
    vector<int> sub;
    go(0, nums, sub, res);
    return res;
  }
private:
  void go(int p, const vector<int> &nums, vector<int> &sub, vector<vector<int> > &res) {
    res.push_back(sub);
    for (int i = p; i < nums.size(); ++i) {
      sub.push_back(nums[i]);
      // NOTE: i + 1
      go(i + 1, nums, sub, res);
      sub.pop_back();
    } 
  }
};
#elif SOLUTION == 3
// reference: https://leetcode.com/problems/subsets/discuss/27278/C%2B%2B-RecursiveIterativeBit-Manipulation
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int> > res = {{}};
    for (const int k : nums) {
      const int n = res.size();
      for (int i = 0; i < n; ++i) {
        res.push_back(res[i]);
        res.back().push_back(k);
      }
    }
    return res;
  }
};
#elif SOLUTION == 4
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int> > res;
    const int n = nums.size();
    const int kind = pow(2, n); 
    for (int i = 0; i < kind; ++i) {
      vector<int> sub;
      for (int t = 0, b = 1; t < n; ++t, b <<= 1) {
        if (i & b) {
          sub.push_back(nums[t]);
        }
      }
      res.emplace_back(sub);
    } 
    return res;
  }
};
#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  auto res = Solution().subsets(nums);
  for (auto &v : res) {
    PRINT_ARRAY(v);
  }
  return 0;
}
