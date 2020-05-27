class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        if (len < 2) return 0;
        int ans = 0;
        for (int i = 0; i < len - 1; ++i) {
            int v = prices[i+1] - prices[i];
            if (v > 0) ans += v;
        }
        return ans;
    }
};
