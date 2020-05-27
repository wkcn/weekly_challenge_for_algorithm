#include "common.h"

class Solution {
  public:
    int nthUglyNumber(int n) {
      if (n <= 0) return 0;
      vector<int> v(n);
      v[0] = 1;
      int p2 = 0;
      int p3 = 0;
      int p5 = 0;
      for (int i = 1; i < n; ++i) {
        int v2 = v[p2] * 2;
        int v3 = v[p3] * 3;
        int v5 = v[p5] * 5;
        v[i] = min(v2, min(v3, v5));
        if (v[i] == v2) ++p2;
        if (v[i] == v3) ++p3;
        if (v[i] == v5) ++p5;
      }
      return v.back();
    }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().nthUglyNumber(n) << endl;
  return 0;
}
