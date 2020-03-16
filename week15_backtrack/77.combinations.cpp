// [TODO] 迭代算法
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k == 0) return {};
        vector<vector<int> > ans;
        vector<int> buf(k, 0);
        go(ans, buf, n, k, 0, 0);
        return ans;
    }
    void go(vector<vector<int> > &ans, vector<int> &buf, int n, int k, int i, int last) {
        if (i >= k) {
            ans.push_back(buf);
            return;
        }
        if (last == n) return; // 这一句可以去掉
        for (int u = last+1; u <= n; ++u) {
            buf[i] = u;
            go(ans, buf, n, k, i+1, u);
        }
    }
};
