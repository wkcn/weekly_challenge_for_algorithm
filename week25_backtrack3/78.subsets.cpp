class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans; ans.push_back({});
        for (int &v : nums) {
            const int len = ans.size();
            for (int i = 0; i < len; ++i) {
                ans.push_back(ans[i]);
                ans.back().push_back(v);
            }
        }
        return ans;
    }
};
