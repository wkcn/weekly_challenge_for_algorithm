// vector<bool>里的元素不是bool!!!
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> buf(n, string(n, '.'));
        vector<char> ver(n, false), left(2 * n, false), right(2 * n, false);
        function<void(int)> F;
        F = [&](int r) {
            if (r >= n) {
                ans.push_back(buf);
                return;
            }
            string &s = buf[r];
            for (int c = 0; c < n; ++c) {
                // 0 <= r, c < n
                // -n < r - c < n  : right
                // 0 < r + c <= 2n - 2 : left
                if (!ver[c]) {
                    char &left_i = left[r + c];
                    char &right_i = right[r - c + n];
                    if (!left_i && !right_i) {
                        s[c] = 'Q';
                        ver[c] = left_i = right_i = true;
                        F(r + 1);
                        ver[c] = left_i = right_i = false;
                        s[c] = '.';
                    }
                }
            }
        };
        F(0);
        return ans;
    }
};
