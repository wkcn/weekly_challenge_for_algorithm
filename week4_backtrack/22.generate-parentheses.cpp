#include "common.h"

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string buf(n * 2, 0);
    go(n, 0, 0, buf, res);
    return res;
  }
private:
  void go(int n, int r, int i, string &buf, vector<string> &res) {
    if (i >= buf.size()) {
      res.push_back(buf);
      return;
    }
    if (n > 0) {
      buf[i] = '(';
      go(n - 1, r + 1, i + 1, buf, res);
    }
    if (r > 0) {
      buf[i] = ')';
      go(n, r - 1, i + 1, buf, res);
    }
  }
};

int main() {
  int n;
  cin >> n;
  for (const string &s : Solution().generateParenthesis(n)) {
    cout << s << endl;
  }
  return 0;
}
