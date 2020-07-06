// 因为取值很小，可以用hash进行计数
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        sort(dominoes.begin(), dominoes.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] > a[1]) swap(a[0], a[1]);
            if (b[0] > b[1]) swap(b[0], b[1]);
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        int i = 0;
        const int len = dominoes.size();
        int cnt = 0;
        while (i < len) {
            int j = i + 1;
            while (j < len && dominoes[j] == dominoes[i]) ++j;
            // [i, j)
            int m = j - i;
            cnt += m * (m - 1) / 2;
            i = j;
        }
        return cnt;
    }
};
