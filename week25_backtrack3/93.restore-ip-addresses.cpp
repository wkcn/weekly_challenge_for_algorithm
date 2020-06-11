#include "common.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        array<int, 3> ip;
        vector<string> ans;
        function<void(int, int, int)> F;
        F = [&](int si, unsigned int v, int pi) {
          if (si >= s.size()) {
            if (pi == 3 && v < 256) {
              string res;
              for (int &u : ip) {
                res += to_string(u); res += '.';
              }
              res += to_string(v);
              ans.emplace_back(std::move(res));
            }
            return;
          }
          if (pi < 3) { 
            if (v < 256) {
              int oldv = ip[pi];
              ip[pi] = v;
              F(si, -1, pi + 1);
              ip[pi] = oldv;
            }
          }
          int y = s[si] - '0';
          if (v == -1) v = y;
          else {
            if (v == 0) return;
            v = v * 10 + y;
          }
          F(si + 1, v, pi);
        };
        F(0, -1, 0);
        return ans;
    }
};

int main() {
  string s;
  cin >> s;
  PRINT_ARRAY(Solution().restoreIpAddresses(s));
  return 0;
}
