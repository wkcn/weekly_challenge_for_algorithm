// 注意输入为空的情况
#include "common.h"

const int lsize[] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
const char lstr[][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> res;
    string buf(digits.size(), ' ');
    go(digits, buf, 0, res); 
    sort(res.begin(), res.end());
    return res;
  }
private:
  void go(const string &digits, string &buf, int p, vector<string> &res) {
    if (p >= digits.size()) {
      res.push_back(buf);
      return;
    }
    int v = digits[p] - '0';
    for (int i = 0; i < lsize[v]; ++i) {
      buf[p] = lstr[v][i];
      go(digits, buf, p + 1, res);
    }
  }
};
#elif SOLUTION == 2

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> res{""};
    for (char &c : digits) {
      vector<string> tmp;
      int v = c - '0';
      for (const string &s : res) {
        for (int i = 0; i < lsize[v]; ++i) {
          tmp.push_back(s + lstr[v][i]);
        }
      }
      res = std::move(tmp);
    }
    return res;
  }
};

#endif

int main() {
  string s;
  cin >> s;
  for (string &t : Solution().letterCombinations(s)) {
    cout << t << endl;
  }
  return 0;
}
