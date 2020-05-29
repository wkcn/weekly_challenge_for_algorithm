class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> dp;
        int ans = 0;
        for (int &x : nums) {
            if (!dp[x])
                dp[x - dp[x-1]] = dp[x + dp[x+1]] = dp[x] = dp[x-1] + dp[x+1] + 1;
            ans = max(dp[x], ans); 
        }
        return ans;
    }
};
