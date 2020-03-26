// TODO: 可以用DP做两遍？
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        if (rows == 0) return {};
        const int cols = matrix[0].size();
        if (cols == 0) return {};
        vector<vector<int> > ans(rows, vector<int>(cols, -1));
        queue<pair<int, int> > q;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == 0) {
                    q.push({r, c});
                    ans[r][c] = 0;
                }
            }
        }
        int step = 1;
        auto F = [&](unsigned int r, unsigned int c) {
            if (r >= rows || c >= cols) return;
            if (ans[r][c] == -1) {
                switch (matrix[r][c]) {
                    case 0:
                        ans[r][c] = 0;
                        break;
                    case 1:
                        ans[r][c] = step;
                        break;
                }
                q.push({r, c});
            }
        };
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c] = q.front(); q.pop();
                F(r+1, c);
                F(r-1, c);
                F(r, c+1);
                F(r, c-1);
            }
            ++step;
        }
        return ans;
    }
};
