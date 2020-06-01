class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        if (N <= 0) return {};
        vector<set<int> > G(N);
        for (auto &e : edges) {
            G[e[0]].insert(e[1]);
            G[e[1]].insert(e[0]);
        }
        vector<int> counts(N); // 以第i个节点为根节点的子树节点数
        vector<int> ans(N);
        dfs1(0, -1, G, counts, ans);
        // 这时ans[0]是正确的
        dfs2(0, -1, G, counts, ans, counts[0]);
        return ans;
    }
    void dfs1(int root, int parent, const vector<set<int> > &G, vector<int> &counts, vector<int> &ans) {
        // return counts
        counts[root] = 1;
        ans[root] = 0;
        for (const int &to : G[root]) {
            if (to == parent) continue;
            dfs1(to, root, G, counts, ans);
            counts[root] += counts[to];
            ans[root] += ans[to] + counts[to];
        }
    }
    void dfs2(int root, int parent, const vector<set<int> > &G, const vector<int> &counts, vector<int> &ans, const int n) {
        for (const int &to : G[root]) {
            if (to == parent) continue;
            ans[to] = ans[root] + n - 2 * counts[to];
            dfs2(to, root, G, counts, ans, n);
        }
    }
};
