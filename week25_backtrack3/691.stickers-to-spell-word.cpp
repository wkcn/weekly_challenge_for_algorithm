#include "common.h"

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        const int n = stickers.size();
        const int m = target.size();
        vector<array<int, 26> > cnts(n, array<int, 26>{0});
        array<set<int>, 26> opts;
        for (int i = 0; i < n; ++i) {
            for (char &c : stickers[i]) {
                ++cnts[i][c - 'a'];
                opts[c - 'a'].insert(i);
            }
        }
        vector<int> dp(1 << m, INT32_MAX);
        dp[0] = 0;

        for (int i = 0; i < ((1 << m) - 1); ++i) {
            if (dp[i] == INT32_MAX) continue;
            // 得到末尾0
            for (int t = 0; t < m; ++t) {
                if (!(i & (1 << t))) {
                    for (const int &o : opts[target[t] - 'a']) {
                        array<int, 26> cnt = cnts[o];
                        int r = i;
                        for (int u = 0; u < m; ++u) {
                            if (!(i & (1 << u)) && cnt[target[u] - 'a'] > 0) {
                                --cnt[target[u] - 'a'];
                                r |= (1 << u);
                            }
                        }
                        dp[r] = min(dp[r], dp[i]+1); 
                    }
                    break;
                }
            }
        }

        return dp.back() == INT32_MAX ? -1 : dp.back();
    }
};

int main() {
  vector<string> stickers;
  string target;
  INPUT_ARRAY(stickers);
  cin >> target;
  cout << Solution().minStickers(stickers, target) << endl;
  return 0;
}
