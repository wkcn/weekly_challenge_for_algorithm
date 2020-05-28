// TODO: 尝试桶排序、几何法
// https://leetcode-cn.com/problems/matrix-cells-in-distance-order/solution/si-chong-jie-fa-shu-zu-pai-xu-tong-pai-xu-bfs-mo-n/
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int dis[R][C];
        vector<vector<int> > ans;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                dis[r][c] = abs(r - r0) + abs(c - c0);
                ans.push_back({r, c});
            }
        }
        sort(ans.begin(), ans.end(), [&dis](vector<int> &a, vector<int> &b) {
            return dis[a[0]][a[1]] < dis[b[0]][b[1]];
        });
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int> > ans;
        queue<pair<int, int> > q;
        bool vis[R][C];
        memset(vis, 0, sizeof(vis));
        q.push({r0, c0});
        vis[r0][c0] = true;
        auto add_pos = [&](unsigned int r, unsigned int c) {
            if (r < R && c < C && !vis[r][c]) {
                vis[r][c] = true;
                q.push({r, c});
            }
        };
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            ans.push_back({r, c});
            add_pos(r+1, c);
            add_pos(r-1, c);
            add_pos(r, c+1);
            add_pos(r, c-1);
        }
        return ans;
    }
};
