class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> cntsm;
        for (int &v : candidates) ++cntsm[v];
        vector<pair<int, int> > cnts(cntsm.begin(), cntsm.end());
        vector<vector<int> > ans;
        vector<int> buf;
        go(0, cnts, target, buf, ans);
        return ans;
    }
    void go(int i, vector<pair<int, int> > &cnts, int target, vector<int> &buf, vector<vector<int> > &ans) {
        if (i >= cnts.size()) return;
        go(i+1, cnts, target, buf, ans);
        int old_buf_size = buf.size();
        for (int k = 0; k < cnts[i].second; ++k) {
            buf.push_back(cnts[i].first);
            target -= cnts[i].first;
            // 注意target == 0放在这里
            if (target == 0) {
                ans.push_back(buf);
            } else if (target < 0) break;
            go(i + 1, cnts, target, buf, ans);
        }
        buf.resize(old_buf_size);
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> buf;
        sort(candidates.begin(), candidates.end());
        go(0, candidates, target, buf, ans);
        return ans;
    }
    void go(int start, vector<int> &candidates, int target, vector<int> &buf, vector<vector<int> > &ans) {
        if (target == 0) {
            ans.push_back(buf);
            return;
        }
        for (int i = start; i < candidates.size() && target >= candidates[i]; ++i) {
            if (i > start && candidates[i-1] == candidates[i]) continue;
            buf.push_back(candidates[i]);
            // i + 1
            go(i + 1, candidates, target - candidates[i], buf, ans);
            buf.pop_back();
        }
    }
};
