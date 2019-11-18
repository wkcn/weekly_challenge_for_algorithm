#include "common.h"

class Solution {
public:
  int maxArea(vector<int>& height) {
    if (height.size() < 2) return 0;
    int i = 0, j = height.size() - 1;
    int best = 0;
    while (i < j) {
      int cap = (j - i) * min(height[i], height[j]);
      if (cap > best) best = cap;
      height[i] < height[j] ? ++i : --j;
    }
    return best;
  }
};

int main() {
  vector<int> height;
  INPUT_ARRAY(height);
  cout << Solution().maxArea(height) << endl;
  return 0;
}
