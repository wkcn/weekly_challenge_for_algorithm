// TODO: catalan number: https://leetcode.com/problems/unique-binary-search-trees/discuss/31671/A-very-simple-and-straight-ans-based-on-MathCatalan-Number-O(N)-timesO(1)space
#include "common.h"

class Solution {
public:
    int numTrees(int n) {
      if (n <= 0) return 0;
      vector<int> counts = {1, 1};
      for (int i = 2; i <= n; ++i) {
        int half = (i - 1) / 2;
        int cnt = 0;
        for (int j = 0; j < half; ++j) {
          cnt += counts[j] * counts[i-1-j];
        }
        cnt *= 2;
        if (i % 2 == 0) {
          cnt += counts[half] * counts[i-1-half] * 2;
        } else {
          cnt += counts[half] * counts[half];
        }
        counts.push_back(cnt);
      }
      return counts[n];
    }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().numTrees(n) << endl;
  return 0;
}
