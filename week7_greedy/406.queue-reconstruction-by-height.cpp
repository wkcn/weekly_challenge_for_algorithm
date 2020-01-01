#include "common.h"
// TODO: 是否有更快的插入方法？
// 先考虑简单的情况，比如身高相等时，再考虑不同身高
// 先排高的人，低的人插进去时不影响高的人的先后顺序
// https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/gen-ju-shen-gao-zhong-jian-dui-lie-by-leetcode/

class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int> > ans;
    sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
      if (a[0] != b[0]) return a[0] > b[0];
      return a[1] < b[1];
    });
    for (auto &p : people) {
      ans.insert(ans.begin() + p[1], p);
    }
    return ans;
  }
};

int main() {
  vector<vector<int> > people;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int h, k;
    cin >> h >> k;
    people.push_back({h, k});
  }
  PRINT_MATRIX(Solution().reconstructQueue(people));
  return 0;
}
