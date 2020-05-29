// 可以递归+剪枝(看best)
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        // 0, 1背包
        int full = 1 << (req_skills.size()); // full要正确！！！
        vector<int> dp(full, -1);
        vector<int> prestate(full, -1);
        vector<int> prepeople(full);
        dp[0] = 0;
        unordered_map<string, int> sid;
        for (string &s : req_skills) {
            sid[s] = sid.size();
        }
        vector<int> skills;
        for (vector<string> &vs : people) {
            int v = 0;
            for (string &s : vs) {
                int i = sid[s];
                v |= 1 << i;
            }
            skills.push_back(v);
        }
        for (int p = 0; p < skills.size(); ++p) {
            int v = skills[p];

            // reverse时是--i!!!!
            for (int i = full - 2; i >= 0; --i) {
                if (dp[i] == -1) continue;
                int u = i | v; // 状态要算对！！！
                if (dp[u] == -1 || dp[i] + 1 < dp[u]) {
                    dp[u] = dp[i] + 1;
                    prestate[u] = i;
                    prepeople[u] = p;
                }
            }
        }
        vector<int> ans;
        int y = full - 1;
        while (prestate[y] != -1) {
            ans.push_back(prepeople[y]);
            y = prestate[y];
        }
        return ans;
    }
};
