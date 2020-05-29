class Solution {
public:
    char findTheDifference(string s, string t) {
        int smask = get_mask(s);
        int tmask = get_mask(t);
        int diff = smask ^ tmask;
        for (int i = 0, j = 1; i < 26; ++i, j <<= 1) {
            if (diff & j) return i + 'a';
        }
        return ' ';
    }
    int get_mask(string &s) {
        int m = 0;
        for (char &c : s) {
          // 这里用异或，因为同样字母可能出现两次
            m ^= 1 << (c - 'a');
        }
        return m;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        char v = 0;
        for (char &c : s) v ^= c;
        for (char &c : t) v ^= c;
        return v;
    }
};
