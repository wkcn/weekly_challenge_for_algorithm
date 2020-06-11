class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int rows = board.size();
        const int cols = board[0].size();
        vector<vector<bool> > vis(rows, vector<bool>(cols));
        function<bool(unsigned int, unsigned int, int)> F;
        F = [&](unsigned int r, unsigned int c, int i) -> bool {
            if (i >= word.size()) return true;
            if (r >= rows || c >= cols) return false;
            if (vis[r][c]) return false;
            if (board[r][c] != word[i]) return false;
            vis[r][c] = true;
            bool valid = F(r + 1, c, i + 1) || \
                F(r - 1, c, i + 1) || \
                F(r, c + 1, i + 1) || \
                F(r, c - 1, i + 1);
            vis[r][c] = false;
            return valid;
        };
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (F(r, c, 0)) return true;
            }
        }
        return false;
    }
};
