#include "common.h"

// TODO: 
// a) 简化代码，四个变量即可
// b) 划分区间法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        if (len < 2) return 0;
        array<int, 4> dp[2]; // 持有，没有，持有，没有
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        dp[0][3] = 0;
        for (int i = 1; i < len; ++i) {
            // 注意，要引用！！！
            auto &next = dp[i & 1];
            auto &cur = dp[(i & 1) ^ 1];
            int v = prices[i];
            next[0] = max(cur[0], -v);
            next[1] = max(cur[1], cur[0] + v);
            next[2] = max(cur[2], cur[1] - v);
            next[3] = max(cur[3], cur[2] + v);
        }
        auto e = dp[(len & 1) ^ 1];
        return max(e[1], e[3]);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        if (len < 2) return 0;
        array<int, 4> dp; // 持有，没有，持有，没有
        dp[0] = -prices[0];
        dp[1] = 0;
        dp[2] = -prices[0];
        dp[3] = 0;
        for (int i = 1; i < len; ++i) {
            int v = prices[i];
            dp[0] = max(dp[0], -v);
            dp[1] = max(dp[1], dp[0] + v);
            dp[2] = max(dp[2], dp[1] - v);
            dp[3] = max(dp[3], dp[2] + v);
        }
        return max(dp[1], dp[3]);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        if (len < 2) return 0;
        // dp[day][k][2]
        const int K = 2;
        // 注意对k的处理！！！！
        int dp[len][K+1][2];
        dp[0][0][0] = 0;
        dp[0][0][1] = INT32_MIN;
        for (int k = 1; k <= K; ++k) {
            dp[0][k][0] = 0;
            dp[0][k][1] = -prices[0];
        }
        for (int i = 1; i < len; ++i) {
            int &price = prices[i];
            for (int k = 0; k <= K; ++k) {
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + price);
                if (k == 0)
                    dp[i][k][1] = dp[i-1][k][1];
                else
                    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - price);
            }
        }
        return dp[len-1][K][0];
    }
};

int main() {
  vector<int> prices;
  INPUT_ARRAY(prices);
  cout << Solution().maxProfit(prices) << endl;
  return 0;
}
