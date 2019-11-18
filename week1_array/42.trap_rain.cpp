#include "common.h"

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

int main() {
  vector<int> height;
  INPUT_ARRAY(height);
  cout << Solution().trap(height) << endl;
  return 0;
}
