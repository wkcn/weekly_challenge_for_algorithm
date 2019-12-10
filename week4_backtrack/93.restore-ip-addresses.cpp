#include "common.h"

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    // 0 ~ 255
    vector<string> res;
    vector<int> ip(4, 0);
    go(0, 0, ip, s, res);
    return res;
  }
private:
  void go(int i, int p, vector<int> &ip, const string &s, vector<string> &res) {
    if (p >= 4) {
      string sip = get_ip(ip);
      res.push_back(sip);
      return;
    }
    int k = s[i] - '0';
  }
  string get_ip(vector<int> &ip) {
    char s[3 * 4 + 3 + 1];
    sprintf(s, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    return s;
  } 
};

int main() {
  return 0;
}
