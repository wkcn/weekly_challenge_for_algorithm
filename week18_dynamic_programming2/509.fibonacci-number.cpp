#include "common.h"

#define SOLUTION 3

#if SOLUTION == 1
// 模板元编程
template <int n>
struct FIB {
    enum {
        value=FIB<n-1>::value + FIB<n-2>::value
    };
};

template <>
struct FIB<0> {
    enum {
        value=0
    };
};


template <>
struct FIB<1> {
    enum {
        value=1
    };
};

template <int N>
int SOLVE(int n) {
  if (n == N) return FIB<N>::value;
  return SOLVE<N < 30 ? N+1 : 0>(n);
  return -1;
}

class Solution {
public:
    int fib(int N) {
        return SOLVE<0>(N);
    }
};

#elif SOLUTION == 2

class Solution {
public:
    int fib(int N) {
      if (N <= 1) return N;
      int a = 0, b = 1;
      for (int i = 2; i <= N; ++i) {
        int c = a + b;
        a = b;
        b = c;
      }
      return b;
    }
};

#elif SOLUTION == 3

// 矩阵
using Mat = array<array<int, 2>, 2>;
using Vec = array<int, 2>;

Mat Mul(const Mat &a, const Mat &b) {
  Mat c;
  c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
  c[0][1] = a[0][0] * b[1][0] + a[0][1] * b[1][1];
  c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
  c[1][1] = a[1][0] * b[1][0] + a[1][1] * b[1][1];
  return c;
}

Mat Pow(const Mat &a, int n) {
  if (n == 0) return {Vec{1, 0}, Vec{0, 1}};
  if (n == 1) return a;
  const int half = n >> 1;
  Mat c = Pow(a, half); 
  c = Mul(c, c);
  if (n % 2) c = Mul(c, a);
  return c;
}

class Solution {
public:
    int fib(int N) {
      if (N <= 1) return N;
      Mat m{Vec{1, 1}, Vec{1, 0}};
      m = Pow(m, N - 1);
      return m[0][0];
    }
};

#endif

int main() {
  int n;
  cin >> n;
  cout << Solution().fib(n) << endl;
  return 0;
}
