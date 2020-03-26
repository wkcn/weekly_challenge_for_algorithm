// TODO: Union Find
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // O -> T
        const int rows = board.size();
        if (rows == 0) return;
        const int cols = board[0].size();
        if (cols == 0) return;
        std::function<void(unsigned int, unsigned int)> dfs;
        dfs = [&](unsigned int r, unsigned int c) {
            if (r >= rows || c >= cols) return;
            if (board[r][c] == 'O') {
                board[r][c] = 'T';
                dfs(r, c+1);
                dfs(r, c-1);
                dfs(r+1, c);
                dfs(r-1, c);
            }
        };
        for (int c = 0; c < cols; ++c) {
            dfs(0, c);
            dfs(rows-1, c);
        }
        for (int r = 1; r < rows-1; ++r) {
            dfs(r, 0);
            dfs(r, cols-1);
        }
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                switch (board[r][c]) {
                    case 'T':
                        board[r][c] = 'O';
                        break;
                    case 'O':
                        board[r][c] = 'X';
                        break;
                }
            }
        }
    }
};
