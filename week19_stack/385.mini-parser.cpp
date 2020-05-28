// 可以不用vector, 直接加入
#include "common.h"
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
public:
  // Constructor initializes an empty nested list.
  NestedInteger() : is_integer(false) {};

  // Constructor initializes a single integer.
  NestedInteger(int value) : is_integer(true), val(value) {};

  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const {
    return is_integer;
  }

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const {
    return val;
  }

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value) {
    is_integer = true;
    val = value;
  }

  // Set this NestedInteger to hold a nested list and adds a nested integer to it.
  void add(const NestedInteger &ni) {
    is_integer = false;
    datas.push_back(ni);
  }

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const {
    return datas;
  }
private:
  bool is_integer;
  int val;
  vector<NestedInteger> datas;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<vector<NestedInteger> > st;
        st.push({});
        int p = 0;
        const int len = s.size();
        while (p < len) {
            const char &h = s[p];
            if (h == ',') {
                ++p;
                continue;
            }
            if (h == ']') {
                // end
                NestedInteger ni;
                for (NestedInteger &v : st.top()) {
                    ni.add(std::move(v));
                }
                st.pop();
                st.top().emplace_back(ni);
                ++p;
                continue;
            }
            if (h == '[') {
                st.push({});
                ++p;
            } else {
                // read number, which ends at ',' or ']'
                char c = s[p];
                bool minus = false;
                if (c == '-') {
                    minus = true;
                    ++p;
                }
                int v = 0;
                while (p < len) {
                    c = s[p];
                    if (isdigit(c)) {
                        v = v * 10 - (c - '0');
                        ++p; // 当c不是数字时，下标不要改变
                    } else break;
                }
                if (!minus) v = -v;
                st.top().push_back(NestedInteger(v));
            }
        }
        return st.top().back();
    }
};

void PrintNest(const NestedInteger &x) {
  if (x.isInteger()) {
    cout << "It is a interger: " << x.getInteger() << endl;
  } else {
    cout << "It is a list" << endl;
    const vector<NestedInteger> &vs = x.getList(); 
    for (const NestedInteger &u : vs) {
      cout << "  ";
      PrintNest(u);
    }
  }
}

int main() {
  string s;
  cin >> s;
  NestedInteger res = Solution().deserialize(s);
  PrintNest(res);
  return 0;
}
