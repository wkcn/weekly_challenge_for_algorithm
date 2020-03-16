// 也可以用递归写, 注意应该在哪里插入即可
// https://leetcode.com/problems/subsets-ii/discuss/30137/Simple-iterative-solution
// [TODO] 递归写法
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int &v : nums) ++counts[v];
        vector<pair<int, int> > ps(counts.begin(), counts.end());
        vector<vector<int> > ans;
        vector<int> buf;
        go(ans, buf, ps, 0);
        return ans;
    }
    void go(vector<vector<int> > &ans, vector<int> &buf, vector<pair<int,int> > &ps, int i) {
        if (i >= ps.size()) {
            ans.push_back(buf);
            return;
        }
        if (ps[i].second > 0) {
            --ps[i].second;
            buf.push_back(ps[i].first);
            go(ans, buf, ps, i);
            buf.pop_back();
            ++ps[i].second;
        }
        go(ans, buf, ps, i+1);
    }
};
