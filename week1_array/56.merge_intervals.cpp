#include "common.h"

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
        }
    );
    const int len = intervals.size();
    vector<vector<int> > res;
    vector<int> it = intervals[0];
    for (int i = 1; i < len; ++i) {
      vector<int> &p = intervals[i];
      if (it[1] < p[0]) {
        res.emplace_back(it);
        it = std::move(p);
      } else {
        if (p[1] > it[1]) it[1] = p[1];
      }
    }
    res.emplace_back(it);
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int> > intervals(n, vector<int>(2));
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    intervals[i][0] = a;
    intervals[i][1] = b;
  }
  PRINT_MATRIX(Solution().merge(intervals));
  return 0;
}
