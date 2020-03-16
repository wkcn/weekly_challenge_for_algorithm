class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int &v : nums) ++counts[v];
        vector<pair<int, int> > ps(counts.begin(), counts.end());
        vector<vector<int> > ans;
        vector<int> buf(nums.size());
        go(ans, buf, nums.size(), ps, 0);
        return ans;
    }
    void go(vector<vector<int> > &ans, vector<int> &buf, int n, vector<pair<int,int> > &ps, int i) {
        if (i == n) {
            ans.push_back(buf);
            return;
        }
        for (int j = 0; j < ps.size(); ++j) {
            if (ps[j].second > 0) {
                --ps[j].second;
                buf[i] = ps[j].first;
                go(ans, buf, n, ps, i+1);
                ++ps[j].second;
            }
        }
    }
};
