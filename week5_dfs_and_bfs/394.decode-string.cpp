#include "common.h"

// 和week4 atom题类似
class Solution {
public:
  string decodeString(string s) {
    int i = 0;
    return Helper(s, i);
  }
private:
  string Helper(const string &s, int &i) {
    string ans;
    const int len = s.size();
    while (i < len && s[i] != ']') {
      const char &c = s[i];
      if (isdigit(c)) {
        int v = c - '0';
        ++i;
        while (i < len && isdigit(s[i])) {
          v *= 10;
          v += s[i++] - '0';
        }
        ++i; // '['
        string r = Helper(s, i);
        ++i; // ']'
        ans += RepeatString(r, v);
      } else {
        ans += s[i++];
      }
    }
    return ans;
  }
  string RepeatString(string &s, int times) {
    if (times == 0) return {};
    if (times == 1) return s;
    string hs = RepeatString(s, times / 2);
    return times % 2 ? hs + hs + s : hs + hs;
  }
};

// TODO: 使用栈非递归法

int main() {
  string s;
  cin >> s;
  cout << Solution().decodeString(s) << endl;
  return 0;
}
