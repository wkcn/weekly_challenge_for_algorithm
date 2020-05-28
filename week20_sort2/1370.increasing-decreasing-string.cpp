class Solution {
public:
    string sortString(string s) {
        if (s.empty()) return "";
        array<int, 26> bucket{0};
        for (char &c : s) ++bucket[c - 'a'];
        string ans;
        int i;
        while (ans.size() < s.size()) {
            for (int i = 0; i < 26; ++i) {
                if (bucket[i] > 0) {
                    ans += i + 'a';
                    --bucket[i];
                }
            }
            for (int i = 25; i >= 0; --i) {
                if (bucket[i] > 0) {
                    ans += i + 'a';
                    --bucket[i];
                }
            }
        }
        return ans;
    }
};
