#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    if (s.empty()) return true;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    const int len = s.size();
    for (int i = 0; i < len; ++i) {
      if (s[i] != t[i]) return false;
    }
    return true;
  }
};
#elif SOLUTION == 2
class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    if (s.empty()) return true;
    array<int, 256> counts{0};
    for (char &c : s) ++counts[c];
    for (char &c : t) --counts[c];
    for (int i = 'a'; i <= 'z'; ++i) if (counts[i] > 0) return false;
    return true;
  }
};
#endif

int main() {
  string s, t;
  cin >> s >> t;
  cout << Solution().isAnagram(s, t) << endl;
  return 0;
}
