#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1 
class Solution {
public:
  int largestPerimeter(vector<int>& A) {
    // 如果A被排序，满足A[n]<=A[n+1]<=A[n+2]
    // 三角形三条边排序后，满足a+b>c, 其中c的值最大，即c>a且c>b
    // 因此c对应A[n+2]
    // 有A[ai] + A[bi] > A[ci]且ci > ai, ci > bi
    // 如果不等式不成立，ai和bi需要变得更大。
    // 因此ai, bi, ci两两之间相差1
    sort(A.begin(), A.end());
    const int len = A.size();
    for (int i = len - 3; i >= 0; --i) {
      if (A[i] + A[i+1] > A[i+2]) return A[i] + A[i+1] + A[i+2];
    }
    return 0;
  }
};
#elif SOLUTION == 2
class Solution {
public:
  int largestPerimeter(vector<int>& A) {
    sort(A.begin(), A.end(), greater<int>());
    const int len = A.size();
    // 迭代器递增稍微快一点，可能是因为cache
    for (int i = 0; i < len - 2; ++i) {
      // A[i] 最大
      if (A[i+1] + A[i+2] > A[i]) return A[i] + A[i+1] + A[i+2];
    }
    return 0;
  }
};
#endif

int main() {
  vector<int> A;
  INPUT_ARRAY(A);
  cout << Solution().largestPerimeter(A) << endl;
  return 0;
}
