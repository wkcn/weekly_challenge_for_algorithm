class Solution {
public:
    string removeDuplicates(string S) {
        const int len = S.size();
        if (len <= 1) return S;
        int i = 0, j = 0;
        while (j < len) {
            if (i > 0 && S[i-1] == S[j]) {
                --i;
                ++j;
            } else {
                S[i++] = S[j++];
            }
        }
        S.resize(i);
        return S;
    }
};
