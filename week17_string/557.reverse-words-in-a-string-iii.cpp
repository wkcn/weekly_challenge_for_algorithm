class Solution {
public:
    string reverseWords(string s) {
        const int slen = s.size();
        int i = 0;
        while (i < slen && s[i] == ' ') ++i;
        while (i < slen) {
            int j = i + 1;
            while (j < slen && s[j] != ' ') ++j;
            // [i, j)
            for (int l = i, r = j - 1; l < r; ++l, --r) swap(s[l], s[r]);
            i = j + 1;
        }
        return s;
    }
};
