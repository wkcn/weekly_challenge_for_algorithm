class Solution {
public:
    bool backspaceCompare(string S, string T) {
        update(S); update(T);
        return S == T;
    }
    void update(string &s) {
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            char &c = s[i];
            if (c == '#') {
                j = max(0, j - 1);
            } else {
                s[j++] = c;
            }
        }
        s.resize(j);
    }
};
