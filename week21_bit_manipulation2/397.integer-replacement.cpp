#include "common.h"

// 3是特例！！要给位运算加括号！！！
// 2147483647是边界例子！
class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT32_MAX) return 32;
        int count = 0;
        while (n > 1) {
            ++count;
            if ((n & 0b11) == 0b01 || n == 3) {
                --n;
            } else if ((n & 0b11) == 0b11) {
                ++n;
            } else {
                n >>= 1;
            }
        }
        return count;
    }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().integerReplacement(n) << endl;
  return 0;
}
