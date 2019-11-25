#include "common.h"

#define SOLUTION 3

#if SOLUTION == 1
class Solution {
public:
  int trap(vector<int>& height) {
    if (height.empty()) return 0;
    const int len = height.size();
    vector<int> left_max(len), right_max(len);
    left_max[0] = height[0];
    for (int i = 1; i < len; ++i) {
      left_max[i] = max(left_max[i-1], height[i]);
    }
    right_max.back() = height.back();
    for (int i = len - 2; i >= 0; --i) {
      right_max[i] = max(right_max[i+1], height[i]);
    }
    int ans = 0;
    for (int i = 0; i < len; ++i) {
      int e = min(left_max[i], right_max[i]);
      if (e > height[i]) {
        ans += e - height[i];
      }
    }
    return ans;
  }
};
#elif SOLUTION == 2

// dynamic programming
// https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/
class Solution {
public:
  int trap(vector<int>& height) {
    const int len = height.size();
    if (len < 3) return 0;
    int left = height[0], right = height.back();
    int i = 0, j = len - 1;
    int ans = 0;
    while (j - i > 1) {
      if (height[i] < height[j]) {
        ++i;
        int t = min(left, right) - height[i];
        if (t > 0) ans += t;
        if (height[i] > left) left = height[i];
      } else {
        --j;
        int t = min(left, right) - height[j];
        if (t > 0) ans += t;
        if (height[j] > right) right = height[j];
      }
    }
    return ans;
  }
};

#elif SOLUTION == 3

class Solution {
public:
  int trap(vector<int>& height) {
    const int len = height.size();
    if (len < 3) return 0;
    int left = height[0], right = height.back();
    int i = 0, j = len - 1;
    int ans = 0;
    while (i < j) {
      if (height[i] < height[j]) {
        height[i] < left ? ans += left - height[i] : left = height[i];
        ++i;
      } else {
        height[j] < right ? ans += right - height[j] : right = height[j];
        --j;
      }
    }
    return ans;
  }
};

#endif

int main() {
  vector<int> height;
  INPUT_ARRAY(height);
  cout << Solution().trap(height) << endl;
  return 0;
}
