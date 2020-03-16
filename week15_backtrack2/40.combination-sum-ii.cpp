#include "common.h"

class Solution {
  public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      // 使用map时，才会按key排序（从小到大）!!!! 
      map<int, int> cnts;
      for (int &v : candidates) {
        ++cnts[v];
      }
      vector<pair<int, int> > ps(cnts.begin(), cnts.end());
      vector<vector<int> > ans;
      vector<int> buf;
      go(ans, buf, ps, 0, target);
      return ans;
    }
    void go(vector<vector<int> > &ans, vector<int> &buf, vector<pair<int, int> > &ps, int i, int rest) {
      if (rest == 0) {
        ans.push_back(buf);
        return;
      }
      if (i >= ps.size()) return;
      if (ps[i].second > 0) {
        int &v = ps[i].first;
        if (v > rest) return;
        buf.push_back(v);
        if (--ps[i].second == 0)
          go(ans, buf, ps, i+1, rest - v);
        else
          go(ans, buf, ps, i, rest - v);
        buf.pop_back();
        ++ps[i].second;
      }
      go(ans, buf, ps, i+1, rest);
    }
};

int main() {
  vector<int> candidates; int target;
  INPUT_ARRAY(candidates); cin >> target;
  PRINT_MATRIX(Solution().combinationSum2(candidates, target));
  return 0;
}
