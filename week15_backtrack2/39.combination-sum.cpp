class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> buf;
        go(ans, buf, candidates, 0, target);
        return ans;
    }
    void go(vector<vector<int> > &ans, vector<int> &buf, vector<int> &candidates, int i, int rest) {
        if (rest == 0) {
            ans.push_back(buf);
            return;
        }
        if (i >= candidates.size()) return;
        int &v = candidates[i];
        if (v > rest) return;
        buf.push_back(v);
        go(ans, buf, candidates, i, rest-v);
        buf.pop_back();
        go(ans, buf, candidates, i+1, rest);
    }
};
