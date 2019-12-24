#include "common.h"

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.empty()) return {};
    const int len = s.size();
    const int L = 2 * len + 3;
    string S(L, '#');
    vector<int> plens(L, 0);
    S[0] = '^';
    S.back() = '$';
    for (int i = 0, j=2; i < len; ++i, j+=2) {
      S[j] = s[i];
    }
    int C = 0, R = 0;
    // 对于一个很长的回文字串，它的中心的两边的回文字串是对称的
    // 注意一下R的取值
    // TODO: 理清R的设置
    for (int i = 2; i <= L - 2; ++i) {
      int mirror_i = 2 * C - i;
      if (mirror_i >= 0) {
        int diff = R - i;
        if (plens[mirror_i] < diff) {
          plens[i] = plens[mirror_i];
          continue;
        }
      }
      int d = 1;
      while (S[i-d] == S[i+d]) ++d;
      plens[i] = --d;
      C = i;
      R = i + d;
    }
    int best_i = 0;
    int best_len = 0;
    for (int i = 2; i <= L - 2; ++i) {
      if (plens[i] > best_len) {
        best_len = plens[i];
        best_i = i;
      }
    }
    // ^#A#B#A#$
    // ^#A#A#$
    // ^#W#A#B#A#$
    // if best_len is odd: best_i - best_len + 1
    // else: best_i - best_len + 1
    return s.substr((best_i - best_len - 1) >> 1, best_len);
  }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().longestPalindrome(s) << endl;
  return 0;
}
