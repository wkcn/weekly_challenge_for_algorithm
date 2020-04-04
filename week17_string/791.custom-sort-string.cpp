#if SOLUTION == 1
class Solution {
public:
    string customSortString(string S, string T) {
        array<int, 256> order{-1};
        for (int i = 0; i < S.size(); ++i) {
            order[S[i]] = i;
        }
        sort(T.begin(), T.end(), [&](char &a, char &b){
            return order[a] < order[b];
        });
        return T;
    }
};

#elif SOLUTION == 2

// 统计数量

class Solution {
public:
    string customSortString(string S, string T) {
        map<char, int> cnts;
        for (char &c : T) ++cnts[c];
        string ans;
        for (char &c : S) {
            int &n = cnts[c];
            if (n > 0) {
                ans += string(n, c);
                n = 0;
            }
        }
        for (auto &[c, n] : cnts) {
            if (n > 0) ans += string(n, c);
        }
        return ans;
    }
};
#endif
