// TODO: 贪心堆的理解与证明
class Solution {
public:
    string reorganizeString(string S) {
        const int len = S.size();
        if (len <= 1) return S;
        const int U = (len + 1) / 2;
        array<int, 26> cnts{0};
        for (char &c : S) {
            ++cnts[c - 'a'];
        }
        int best = 0;
        int best_i;
        for (int i = 0; i < 26; ++i) {
            if (cnts[i] > best) {
                best = cnts[i];
                best_i = i;
            }
        }
        if (best > U) return {};
        // 0, 1, 2, 3, 4, 5
        // 0, 3, 1, 4, 2, 5

        // 0, 1, 2, 3, 4
        // 0, 3, 1, 4, 2
        int ind = 0;
        for (int e = 0; e < len; ++e) {
            S[ind] = best_i + 'a';
            if (--cnts[best_i] == 0) {
                for (int i = 0; i < 26; ++i) {
                    if (cnts[i] > 0) {
                        best_i = i;
                        break;
                    }
                }
            }
            ind += 2;
            if (ind >= len) ind = 1; // 包含等于
        }
        return S;
    }
};
