class Solution {
public:
    string reverseStr(string s, int k) {
        const int slen = s.size();
        const int k2 = k << 1;
        for (int i = 0; i < slen; i += k2) {
            // [i, i+k)
            for (int l = i, r = min(i+k, slen)-1; l < r;++l, --r) {
                swap(s[l], s[r]);
            }
        }
        return s;
    }
};
