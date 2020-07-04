// 使用队列会更好，因为跳过了很多不必要的未访问的格子
// 方法1是方法2的优化
#include "common.h"

#define SOLUTION 3

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
#elif SOLUTION == 3

struct DNode {
    array<DNode*, 26> nodes;
    bool leaf;
    DNode() : nodes{nullptr}, leaf(false) {

    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.size();
        if (n == 0) return false;
        DNode *root = new DNode();
        for (string &s : wordDict) {
            DNode *r = root;
            for (char &c : s) {
                DNode *&u = r->nodes[c - 'a'];
                if (!u) u = new DNode();
                r = u;
            }
            r->leaf = true;
        }
        // 注意是n+1
        vector<bool> vis(n + 1, false);
        vis[0] = true;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) continue;
            DNode *r = root;
            for (int t = i; t < n; ++t) {
                r = r->nodes[s[t] - 'a'];
                if (!r) break;
                // t+1
                if (r->leaf) vis[t+1] = true;
            }
        }
        return vis.back();
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
