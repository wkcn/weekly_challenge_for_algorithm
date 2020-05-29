#include "common.h"
// 不能用前缀和+二分搜索的形式，因为A存在负数！！！
// 即使对每个元素都加一个常数让其变为正数，但不同段长度不同，导致即使是正确的段，和也不相等
#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int su = 0;
        for (int x:A) su += x;
        if (su % 3) return false;
        const int len = A.size();
        su /= 3;
        int cnt = 0;
        int ps = 0;
        for (int x: A) {
            ps += x;
            if (ps == su) {
                ps = 0;
                ++cnt;
            }
        }
        return cnt >= 3;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
      int su = accumulate(A.begin(), A.end(), 0);
      if (su % 3) return false;
      int i = 0;
      const int len = A.size();
      int ps = 0;
      while (i < len) {
        ps += A[i++];
        if (ps == su / 3) break;
      }
      if (i >= len) return false;
      ps = 0;
      while (i < len) {
        ps += A[i++];
        if (ps == su / 3) break;
      }
      return i < len;
    }
};
#endif

int main() {
  vector<int> A;
  INPUT_ARRAY(A);
  cout << Solution().canThreePartsEqualSum(A) << endl;
  return 0;
}
