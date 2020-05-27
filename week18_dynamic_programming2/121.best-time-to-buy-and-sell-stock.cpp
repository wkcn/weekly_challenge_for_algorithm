// 可以不用数组记录最小值
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        if (len == 0) return 0;
        vector<int> mp(len);
        mp[0] = prices[0];
        for (int i = 1; i < len; ++i) {
            mp[i] = min(mp[i-1], prices[i]);
        }
        int ans = 0;
        for (int i = 1; i < len; ++i) {
            ans = max(ans, prices[i] - mp[i]);
        }
        return ans;
    }
};
