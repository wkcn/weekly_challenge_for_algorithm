#include "common.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
      int v = 0;
      while (n > 0) {
        ++v;
        n &= n - 1;
      }
      return v;
    }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().hammingWeight(n) << endl;
  return 0;
}
