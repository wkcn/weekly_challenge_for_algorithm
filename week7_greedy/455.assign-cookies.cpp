#include "common.h"

#define SOLUTION 3

#if SOLUTION == 1
class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    const int len_g = g.size();
    int content = 0;
    int gi = 0;
    // gi和content可以合并
    for (const int x : s) {
      if (gi >= len_g) break;
      if (x >= g[gi]) {
        ++content;
        ++gi;
      }
    }
    return content;
  }
};
#elif SOLUTION == 2
class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    const int len_g = g.size();
    int content = 0;
    auto s_start = s.begin();
    for (const int x : g) {
      s_start = lower_bound(s_start, s.end(), x);
      if (s_start == s.end()) break;
      ++content;
      ++s_start;
    }
    // s_start和content不可以合并
    return content;
  }
};
#elif SOLUTION == 3
class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    const int len_g = g.size(), len_s = s.size();
    int gi = 0, si = 0;
    while (gi < len_g && si < len_s) {
      if (s[si] >= g[gi]) ++gi;
      ++si;
    }
    return gi;
  }
};
#endif

int main() {
  vector<int> g, s;
  INPUT_ARRAY(g);
  INPUT_ARRAY(s);
  cout << Solution().findContentChildren(g, s) << endl;
  return 0;
}
