#if SOLUTION == 1
class Solution {
public:
    bool isMatch(string s, string p) {
        const int slen = s.size();
        const int plen = p.size();
        // 将x*改为*x
        for (int i = 1; i < plen; ++i) {
            if (p[i] == '*') {
                swap(p[i-1], p[i]);
            }
        }
        return isMatch(s, p, 0, 0, slen, plen);
    }
    bool isMatch(const string &s, const string &p, int si, int pi, int slen, int plen) {
        if (pi >= plen) return si >= slen;
        const char &pc = p[pi];
        if (pc == '.') {
            if (si >= slen) return false;
            return isMatch(s, p, si+1, pi+1, slen, plen);
        } else if (pc == '*') {
            // 后面的可能是字母或.
            // 0
            if (isMatch(s, p, si, pi+2, slen, plen)) return true;
            if (si >= slen) return false;
            const char &ac = p[pi+1];
            // 1 or 1+
            if (ac == '.' || ac == s[si]) {
                if (isMatch(s, p, si+1, pi+2, slen, plen) ||
                    isMatch(s, p, si+1, pi, slen, plen)
                   ) return true;
            }
        } else {
            // pc 为字母
            if (si >= slen) return false;
            if (pc == s[si] && isMatch(s, p, si+1, pi+1, slen, plen)) return true;
        }
        return false;
    }
};
#elif SOLUTION == 2

// TODO: 空间O(n)的DP
class Solution {
public:
    bool isMatch(string s, string p) {
        const int slen = s.size();
        const int plen = p.size();
        vector<vector<bool> > dp(slen + 1, vector<bool>(plen + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < plen && p[i] == '*'; i += 2) dp[0][i+1] = true;
        for (int i = 0; i < slen; ++i) {
            for (int j = 0; j < plen; ++j) {
                dp[i+1][j+1] = ((p[j] == s[i] || p[j] == '.') && dp[i][j]) ||
                    (p[j] == '*' &&
                        (dp[i+1][j-1] ||
                            (
                                (p[j-1]==s[i] || p[j-1] == '.') &&
                                (dp[i][j+1] || dp[i][j-1])
                            )
                        )
                    );
            }
        }
        return dp[slen][plen];
    }
};


#endif
