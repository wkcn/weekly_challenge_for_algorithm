// 注意一些特例，比如0开头
#include "common.h"

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    // 0 ~ 255
    vector<string> res;
    // 注意未填写的情况
    vector<int> ip(4, -1);
    go(0, 0, ip, s, res);
    return res;
  }
private:
  void go(int i, int p, vector<int> &ip, const string &s, vector<string> &res) {
    if (i >= s.size()) {
      // NOTE: p >= 3
      if (p >= 3) {
        string sip = get_ip(ip);
        res.push_back(sip);
      }
      return;
    }
    // NOTE: p >= 4
    if (p >= 4) return;
    if (ip[p] != -1)
      go(i, p+1, ip, s, res);
    int k = s[i] - '0';
    int ov = ip[p];
    if (ov == 0) return; // 每个数字必填写
    int nv = (ov == -1 ? 0 : ov) * 10 + k;
    if (nv <= 255) {
      ip[p] = nv;
      go(i+1, p, ip, s, res);
      ip[p] = ov;
    }
  }
  string get_ip(vector<int> &ip) {
    char s[3 * 4 + 3 + 1];
    sprintf(s, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    return s;
  } 
};

int main() {
  string s;
  cin >> s;
  for (string &s : Solution().restoreIpAddresses(s)) {
    cout << s << endl;
  }
  return 0;
}
