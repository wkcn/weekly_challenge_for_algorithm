#include "common.h"

class Solution {
public:
  int mySqrt(int x) {
    if (x == 0) return 0;
    if (x <= 3) return 1;
    int i = 1, j = x / 2 + 1;
    while (i < j) {
      int mid = i + (j - i) / 2;
      int r = x % mid;
      int q = x / mid;
      if (r == 0 && q == mid) return mid;
      // if mid * mid < num
      mid < q + (r > 0) ? i = mid + 1 : j = mid;
    }
    return --i;
  }
};

int main() {
  int x;
  cin >> x;
  cout << Solution().mySqrt(x) << endl;
  return 0;
}
