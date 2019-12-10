#include "common.h"

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    if (n <= 0) return {};
    if (n == 1) return {{"Q"}};
    vector<vector<string> > res;
    vector<string> buf(n, string(n, '.'));
    vector<bool> cols(n, false); 
    // if n == 3, slash in [-2, 2]
    // n > 1
    vector<bool> slashes[2];
    slashes[0].resize(2 * (n - 1) + 1, false);
    slashes[1].resize(2 * (n - 1) + 1, false);
    go(0, n, cols, slashes, buf, res);
    return res;
  }
private:
  void go(int r, int n, vector<bool> &cols, vector<bool> slashes[2], vector<string> &buf, vector<vector<string> > &res) {
    if (r >= n) {
      res.push_back(buf);
      return;
    }
    for (int c = 0; c < n; ++c) {
      if (!cols[c]) {
        int t0 = r - c + (n - 1);
        int t1 = c + r;
        if (!slashes[0][t0] && !slashes[1][t1]) {
          cols[c] = slashes[0][t0] = slashes[1][t1] = true;
          buf[r][c] = 'Q';
          go(r + 1, n, cols, slashes, buf, res);
          buf[r][c] = '.';
          cols[c] = slashes[0][t0] = slashes[1][t1] = false;
        }
      }
    }
  }
};

int main() {
  int n;
  cin >> n;
  auto res = Solution().solveNQueens(n);
  for (auto &v : res) {
    for (string &s : v) {
      cout << s << endl;
    }
    cout << "===========" << endl;
  }
  return 0;
}
