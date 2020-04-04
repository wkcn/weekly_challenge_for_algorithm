// 特别要注意空格的处理，不要连续两个空格
class Solution {
public:
    string reverseWords(string s) {
        // AB -> BA
        // (AB)^T = B^T A^T
        int slen = s.size();
        int i = 0, j = 0;
        bool space = false;
        bool last_is_char = false;
        for (; j < slen; ++j) {
            if (s[j] != ' ') {
                if (space) {
                    s[i++] = ' ';
                    space = false;
                }
                s[i++] = s[j];
                last_is_char = true;
            } else {
                if (last_is_char) {
                    space = true;
                    last_is_char = false;
                }
            }
        }
        slen = i;
        s.resize(slen);
        i = 0;
        while (i < slen) {
            j = i + 1;
            while (j < slen && s[j] != ' ') ++j;
            // [i, j)
            reverse(s.begin()+i, s.begin()+j);
            i = j + 1;
            while (i < slen && s[i] == ' ') ++i;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
