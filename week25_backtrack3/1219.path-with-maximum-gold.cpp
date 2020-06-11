class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        const int rows = grid.size();
        if (rows == 0) return 0;
        const int cols = grid[0].size();
        if (cols == 0) return 0;
        int best = 0;
        function<void(unsigned int, unsigned int, int)> F;
        F = [&](unsigned int r, unsigned int c, int v) {
            if (r >= rows || c >= cols) return;
            if (grid[r][c] <= 0) return;
            v += grid[r][c];
            best = max(best, v);
            grid[r][c] = -grid[r][c];
            F(r + 1, c, v);
            F(r - 1, c, v);
            F(r, c + 1, v);
            F(r, c - 1, v);
            grid[r][c] = -grid[r][c]; // recover
        };
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c]) {
                    F(r, c, 0);
                }
            }
        }
        return best;
    }
};
