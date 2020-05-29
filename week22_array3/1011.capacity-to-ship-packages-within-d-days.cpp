#include "common.h"
// 给出上下限，用二分
// 给清上下限
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        const int len = weights.size();
        vector<int> presum(len + 1);
        presum[0] = 0;
        for (int i = 0; i < len; ++i) presum[i+1] = presum[i] + weights[i];
        int lo = (*max_element(weights.begin(), weights.end()));
        int hi = presum.back() + 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            check(mid, presum, D) ? hi = mid : lo = mid + 1;
        }
        return lo;
    }
    bool check(int u, const vector<int> &presum, int D) {
        auto p = presum.begin();
        while (D-- > 0) {
            p = upper_bound(p, presum.end(), (p == presum.begin() ? u : u + *prev(p)));
            if (p == presum.end()) return true;
        }
        return p == presum.end();
    }
};

int main() {
  vector<int> weights; int D;
  INPUT_ARRAY(weights); cin >> D;
  cout << Solution().shipWithinDays(weights, D) << endl;
  return 0;
}
