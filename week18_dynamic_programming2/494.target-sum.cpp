// TODO: DP
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int len = nums.size();
        vector<map<int, int> > vs(len+1); 
        vs[0][0] = 1;
        for (int i = 1; i <= len; ++i) {
            // update vs[i]
            const int &v = nums[i-1];
            for (auto &p : vs[i-1]) {
                const int &u = p.first;
                int cnt = p.second; 
                vs[i][u + v] += cnt;
                vs[i][u - v] += cnt;
            }
        }
        return vs[len][S];
    }
};
