#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0) return 1;
    int half_n = n / 2;
    if (n < 0) {
      x = 1 / x;
      half_n = -half_n;
    }
    // 当n为负数时, n / 2 != (n >> 1)
    double p = myPow(x, half_n);
    p *= p;
    return (n & 1) ? p * x : p;
  }
};
#elif SOLUTION == 2
class Solution {
public:
  double myPow(double x, int n) {
    double base = n > 0 ? x : 1 / x;
    double res = 1;
    while (n != 0) {
      if (n & 1) res *= base;
      n /= 2;
      base *= base;
    }
    return res;
  }
};
#endif

int main() {
  double x;
  int n;
  cin >> x >> n;
  cout << Solution().myPow(x, n) << endl;
  return 0;
}
