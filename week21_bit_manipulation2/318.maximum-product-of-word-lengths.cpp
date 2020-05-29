class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> ma;
        for (string &s : words) {
            int v = get_mask(s);
            ma[v] = max(ma[v], (int)s.size());
        }
        int ans = 0;
        for (auto px = ma.begin(); px != ma.end(); ++px) {
            for (auto py = next(px); py != ma.end(); ++py) {
                // 要给位运算加括号！！！
                if ((px->first & py->first) == 0) {
                    ans = max(ans, px->second * py->second);
                }
            }
        }
        return ans;
    }
    int get_mask(string &s) {
        int v = 0;
        for (char &c : s) {
            v |= 1 << (c - 'a');
        }
        return v;
    }
};
