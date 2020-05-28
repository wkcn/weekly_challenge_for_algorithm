#include "common.h"

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dirs;
        int p = 0;
        const int len = path.size();
        while (p < len) {
            while (p < len && path[p] == '/') ++p;
            int start = p;
            while (p < len && path[p] != '/') ++p;
            string dname = path.substr(start, p - start);
            if (dname.empty()) break; // 有可能末尾以/结束，导致dname为空
            if (dname == ".") {
              continue;
            } else if (dname == "..") {
              if (!dirs.empty())
                dirs.pop();
            } else {
              dirs.emplace(move(dname));
            }
        }
        stack<string> rst;
        while (!dirs.empty()) {
            rst.push(dirs.top()); dirs.pop();
        }
        if (rst.empty()) return "/";
        string ans;
        while (!rst.empty()) {
            ans += '/';
            ans += rst.top();
            rst.pop();
        }
        return ans;
    }
};

int main() {
  string path;
  cin >> path;
  cout << Solution().simplifyPath(path) << endl;
  return 0;
}
