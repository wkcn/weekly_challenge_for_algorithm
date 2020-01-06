#include "common.h"

#define SOLUTION 1

#if SOLUTION == 1
class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num <= 1) return true;
    int lo = 1, hi = num / 2 + 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      // mid * mid 可能会溢出
      int r = num % mid;
      int q = num / mid;
      if (r == 0 && q == mid) return true;
      // 列公式并展开
      // if mid * mid < num
      //   then mid < float(num / mid)
      //   then mid < num / mid + (num % mid > 0)
      mid < q + (r > 0) ? lo = mid + 1 : hi = mid;
    }
    return false;
  }
};
#elif SOLUTION == 2
// Newton's method
// https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
// https://leetcode.com/problems/valid-perfect-square/discuss/83874/A-square-number-is-1%2B3%2B5%2B7%2B...-JAVA-code
#endif

int main() {
  int num;
  cin >> num;
  cout << Solution().isPerfectSquare(num) << endl;
  return 0;
}
