// TODO: 可以做进一步的状态压缩
class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        const int len = prices.size();
        if (len < 2) return 0;
        K = min(K, len / 2); // 限制K
        // dp[day][k][2]
        // 注意对k的处理！！！！
        int dp[2][K+1][2];
        dp[0][0][0] = 0;
        dp[0][0][1] = INT32_MIN;
        for (int k = 1; k <= K; ++k) {
            dp[0][k][0] = 0;
            dp[0][k][1] = -prices[0];
        }
        for (int i = 1; i < len; ++i) {
            int &price = prices[i];
            auto &cur = dp[i & 1];
            auto &last = dp[(i & 1) ^ 1];
            for (int k = 0; k <= K; ++k) {
                cur[k][0] = max(last[k][0], last[k][1] + price);
                if (k == 0)
                    cur[k][1] = last[k][1];
                else
                    cur[k][1] = max(last[k][1], last[k-1][0] - price);
            }
        }
        return dp[(len & 1) ^ 1][K][0];

    }
};
