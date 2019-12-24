#include "common.h"

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 0) return 0;
    if (n <= 2) return n;
    int steps[2] = {1, 2};
    // 对初始值有要求的
    bool flag = 1;
    for (int i = 3; i <= n; ++i) {
      flag = !flag;
      steps[flag] += steps[!flag];
    }
    return steps[flag];
  }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().climbStairs(n) << endl;
  return 0;
}
