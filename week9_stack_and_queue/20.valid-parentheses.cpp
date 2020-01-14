#include "common.h"

#define CHECK(st, p) \
  if (st.empty()) return false; \
  if (st.top() != p) return false; \
  st.pop()

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (int c : s) {
      switch (c) {
        case '(':
        case '[':
        case '{':
          st.push(c);
          break;
        case ')':
          CHECK(st, '(');
          break;
        case ']':
          CHECK(st, '[');
          break;
        case '}':
          CHECK(st, '{');
          break;
      }
    }
    return st.empty();
  }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().isValid(s) << endl;
  return 0;
}
