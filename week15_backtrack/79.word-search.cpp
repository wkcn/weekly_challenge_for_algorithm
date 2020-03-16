#if SOLUTION == 1
// 52ms, 18.1MB
// 性能瓶颈在offset, 移出来能提升速度，展开的话提升得更多
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        const int rows = board.size();
        if (rows == 0) return false;
        const int cols = board[0].size();
        if (cols == 0) return false;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (go(board, word, rows, cols, r, c, 0)) return true;
            }
        }
        return false;
    }
    bool go(vector<vector<char> > &board, const string &word, const int rows, const int cols, int r, int c, int i) {
        if (i >= word.size()) return true;
        if (board[r][c] != word[i]) return false;
        if (i == word.size() - 1) return true;
        board[r][c] = 0;
        for (const auto &p : vector<pair<int,int> >{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}) {
            unsigned int nr = p.first + r;
            unsigned int nc = p.second + c;
            if (nr < rows && nc < cols) {
                if (go(board, word, rows, cols, nr, nc, i+1)) return true;
            }
        }
        board[r][c] = word[i];
        return false;
    }
};
#elif SOLUTION == 2
// 将偏移量移出来，能从64ms -> 24ms
// 将偏移量展开，24ms -> 20ms
// 20ms, 9.4MB
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        const int rows = board.size();
        if (rows == 0) return false;
        const int cols = board[0].size();
        if (cols == 0) return false;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (go(board, word, rows, cols, r, c, 0)) return true;
            }
        }
        return false;
    }
    bool go(vector<vector<char> > &board, const string &word, const unsigned int rows, const unsigned int cols, unsigned int r, unsigned int c, int i) {
        if (r >= rows || c >= cols) return false;
        if (board[r][c] != word[i]) return false;
        if (i == word.size() - 1) return true;
        board[r][c] = 0;
        if (go(board, word, rows, cols, r+1, c, i+1)) return true;
        if (go(board, word, rows, cols, r-1, c, i+1)) return true;
        if (go(board, word, rows, cols, r, c+1, i+1)) return true;
        if (go(board, word, rows, cols, r, c-1, i+1)) return true;
        board[r][c] = word[i];
        return false;
    }
};
#endif
