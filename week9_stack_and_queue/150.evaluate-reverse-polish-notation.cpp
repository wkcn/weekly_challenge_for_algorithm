#include "common.h"

// 注意a和b的先后顺序！
#define TOKEN(st, op) \
  b = st.top(); st.pop(); \
  a = st.top(); st.pop(); \
  st.push(a op b);

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> st;
    int a, b;
    for (string &s : tokens) {
      // 有些数字带符号，如"+3", "-2"
      if (s.size() == 1) {
        char &c = s[0];
        switch (c) {
          case '+':
            TOKEN(st, +);
            break;
          case '-':
            TOKEN(st, -);
            break;
          case '*':
            TOKEN(st, *);
            break;
          case '/':
            TOKEN(st, /);
            break;
          default:
            st.push(stoi(s));
        }
      } else {
        st.push(stoi(s));
      }
    }
    return st.top();
  }
};

int main() {
  int n;
  cin >> n;
  vector<string> tokens;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    tokens.push_back(s);
  }
  cout << Solution().evalRPN(tokens) << endl;
  return 0;
}
