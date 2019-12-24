// 使用队列会更好，因为跳过了很多不必要的未访问的格子
// 方法1是方法2的优化
#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    const int len = s.size();
    if (len <= 0) return true;
    queue<int> q;
    q.push(0);
    vector<bool> vis(len, false); 
    vis[0] = true;
    while (!q.empty()) {
      int start = q.front(); q.pop();
      for (const string &w : wordDict) {
        const int wlen = w.size();
        const int end = start + wlen;
        // end == len时有可能刚好匹配最后一个字母
        if (end <= len) {
          if (s.substr(start, wlen) == w) {
            if (end >= len) return true;
            if (!vis[end]) {
              vis[end] = true;
              q.push(end);
            }
          } 
        }
      }
    }
    return false;
  }
};
#elif SOLUTION == 2
// 这种方法会访问到很多未访问的格子
class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    const int len = s.size();
    if (len <= 0) return true;
    vector<bool> vis(len + 1, false);
    vis[0] = true;
    for (int i = 1; i <= len; ++i) {
      for (const string &w : wordDict) {
        const int wlen = w.size();
        // 用单词枚举开头比先枚举开头好
        const int j = i - wlen; // start
        if (j >= 0 && vis[j]) {
          if (s.substr(j, wlen) == w) {
            vis[i] = true;
            break;
          }
        }
      }
    }
    return vis[len];
  }
};
#endif

int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> wordDict;
  for (int i = 0; i < n; ++i) {
    string buf; cin >> buf;
    wordDict.push_back(buf);
  }
  cout << Solution().wordBreak(s, wordDict) << endl;
  return 0;
}
