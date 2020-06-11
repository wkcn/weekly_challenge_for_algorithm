class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1; // 特殊情况
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += get_num(i);
        }
        return ans;
    }
    int get_num(int k) {
        if (k == 1) return 10; // 包含0
        // 9 * 9 * 8 * 7 * 6 * ...
        int res = 9;
        for (int i = 2, u = 9; i <= k && u >= 0; ++i, --u) {
            res *= u;
        }
        return res;
    }
};
