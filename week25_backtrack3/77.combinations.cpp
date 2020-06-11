class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> buf(k);
        function<void(int, int)> F;
        F = [&](int i, int j) {
            if (j == k) {
                ans.push_back(buf);
                return;
            }
            if (i > n) return;
            F(i + 1, j);
            buf[j] = i;
            F(i + 1, j + 1);
        };
        F(1, 0);
        return ans;
    }
};
