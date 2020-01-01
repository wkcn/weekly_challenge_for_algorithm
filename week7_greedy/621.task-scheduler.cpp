#include "common.h"
// 贪心考虑最值优先
// https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode/

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    array<int, 26> counts{0};
    for (char &c : tasks) {
      ++counts[c - 'A'];
    }
    int ma = counts[0];
    for (int i = 1; i < 26; ++i) {
      if (counts[i] > ma) ma = counts[i];
    }
    int eq = -1; // 排除最大值
    for (int i = 0; i < 26; ++i) {
      if (counts[i] == ma) ++eq;
    }
    int idle = (ma - 1) * n;
    int su = tasks.size();
    idle -= (su - ma - eq);
    return idle > 0 ? su + idle : su; 
  }
};

int main() {
  string s;
  cin >> s;
  vector<char> tasks(s.data(), s.data() + s.size());
  int n;
  cin >> n;
  cout << Solution().leastInterval(tasks, n) << endl;
  return 0;
}
