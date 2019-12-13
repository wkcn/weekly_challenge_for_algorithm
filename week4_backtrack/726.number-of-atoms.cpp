#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  string countOfAtoms(string formula) {
    map<string, int> ma = helper(formula, 0, formula.size());
    string s;
    for (auto &p : ma) {
      s += p.first;
      if (p.second > 1) s += to_string(p.second);
    }
    return s;
  }
  map<string, int> helper(const string &formula, int start, int end) {
    map<string, int> ma;
    int i = start;
    while (i < end) {
      const char &c = formula[i];
      if (c == '(') {
        ++i;
        int left_i = i;
        int left = 1;
        while (i < end) {
          const char &c = formula[i];
          if (c == '(') ++left;
          else if (c == ')') {
            --left;
            if (left == 0) {
              map<string, int> subma = helper(formula, left_i, i); 
              int num = get_num(formula, ++i, end);
              for (auto &p : subma) {
                ma[p.first] += p.second * num;
              }
              break;
            }
          }
          ++i;
        }
      } else {
        // atom
        string atom;
        atom += c;
        ++i;
        while (i < end) {
          const char &c = formula[i];
          if (c >= 'a' && c <= 'z') {
            atom += c;
            ++i;
          } else break;
        }
        int num = get_num(formula, i, end);
        ma[atom] += num;
      }
    }
    return ma;
  }
private:
  int get_num(const string &formula, int &i, int end) {
    const char &c = formula[i];
    if (c >= '0' && c <= '9') {
      int v = c - '0';
      ++i;
      while (i < end) {
        const char &c = formula[i];
        if (c >= '0' && c <= '9') {
          v = v * 10 + c - '0';
          ++i;
        } else break;
      }
      return v;
    }
    return 1;
  }
};
#elif SOLUTION == 2
class Solution {
public:
  string countOfAtoms(string formula) {
    stack<map<string, int> > st;
    st.push({});
    int i = 0;
    const int len = formula.size();
    while (i < len) {
      string t = get_atom(formula, i);
      if (t[0] == '(') {
        st.push({});
      } else if (t[0] == ')') {
        int num = get_num(formula, i);
        map<string, int> ma = std::move(st.top()); st.pop();
        for (auto &p : ma) {
          st.top()[p.first] += p.second * num;
        }
      } else {
        int num = get_num(formula, i);
        st.top()[t] += num;
      }
    }
    string out;
    for (auto &p : st.top()) {
      out += p.first;
      if (p.second > 1) out += to_string(p.second);
    }
    return out;
  }
private:
  string get_atom(const string &s, int &i) {
    const int len = s.size();
    string buf;
    if (i < len) {
      const char &c = s[i];
      ++i;
      if (c == '(' || c == ')') return {c};
      buf += c;
      while (i < len) {
        const char &c = s[i];
        if (c >= 'a' && c <= 'z') {
          buf += c; ++i;
        } else break;
      }
    }
    return buf;
  }
  int get_num(const string &formula, int &i) {
    const int len = formula.size();
    const char &c = formula[i];
    if (c >= '0' && c <= '9') {
      int v = c - '0';
      ++i;
      while (i < len) {
        const char &c = formula[i];
        if (c >= '0' && c <= '9') {
          v = v * 10 + c - '0';
          ++i;
        } else break;
      }
      return v;
    }
    return 1;
  }
};
#endif

int main() {
  string formula;
  cin >> formula;
  cout << Solution().countOfAtoms(formula) << endl;
  return 0;
}
