// 有很多要注意的细节
// TODO: 用正则表达式解决
#include "common.h"

class Solution {
public:
    string validIPAddress(string IP) {
        if (CheckIPv4(IP)) return "IPv4";
        if (CheckIPv6(IP)) return "IPv6";
        return "Neither";
    }
    bool CheckIPv4(const string &IP) {
        int n_group = 1;
        int v = -1;
        for (const char &c : IP) {
            if (c == '.') {
                if (v < 0 || v > 255) return false;
                v = -1; ++n_group;
            } else {
                if (!isdigit(c)) return false; // 避免IPv6
                int t = c - '0';
                if (v == -1) v = t;
                else {
                    if (v == 0) return false; // double 0
                    v = v * 10 + t;
                    if (v > 255) return false; // 避免溢出
                }
            }
        }
        return (v >= 0 && v <= 255 && n_group == 4);
    }
    bool CheckIPv6(const string &IP) {
        int n_group = 1;
        int cnt = 0;
        for (const char &c : IP) {
            if (c == ':') {
                if (cnt <= 0 || cnt > 4) return false;
                ++n_group;
                cnt = 0;
            } else if (isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) {
                    ++cnt;
            } else return false;
        }
        return cnt >= 1 && cnt <= 4 && n_group == 8;
    }
};

int main() {
  string IP;
  cin >> IP;
  cout << Solution().validIPAddress(IP) << endl;
  return 0;
}
