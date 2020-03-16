class Solution {
public:
    string getPermutation(int n, int k) {
        if (n <= 0) return {};
        vector<int> f(n);
        f[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = f[i-1] * i;
        }
        list<int> li;
        for (int i = 1; i <= n; ++i) {
            li.push_back(i);
        }
        string ans;
        --k;
        for (int i = n-1; i>= 0; --i) {
            int u = k / f[i];
            auto p = li.begin();
            while (u--) ++p;
            ans += to_string(*p);
            li.erase(p);
            k %= f[i];
        }
        return ans;
    }
};
