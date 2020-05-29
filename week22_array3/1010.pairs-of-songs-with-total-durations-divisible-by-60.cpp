// TODO: 算组合数量的方法
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        array<int, 60> dp{0};
        int ans = 0;
        for (int &t : time) {
            int y = t % 60;
            ans += dp[(60 - y) % 60]; // 注意y == 0的情况
            ++dp[y];
        }
        return ans;
    }
};
