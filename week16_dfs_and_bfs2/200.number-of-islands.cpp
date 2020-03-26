class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int rows = grid.size();
        if (rows == 0) return 0;
        const int cols = grid[0].size();
        if (cols == 0) return 0;
        std::function<void(unsigned r, unsigned c)> dfs;
        dfs = [&](unsigned r, unsigned c) {
            if (r >= rows || c >= cols) return;
            if (grid[r][c] == '1') {
                grid[r][c] = 'x';
                dfs(r+1, c);
                dfs(r-1, c);
                dfs(r, c+1);
                dfs(r, c-1);
                // 这里不能让grid[r][c]马上设回'1'
            }
        };
        int ans = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    ++ans;
                    dfs(r, c);
                }
            }
        }
        return ans;
    }
};
