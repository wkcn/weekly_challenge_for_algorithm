#if SOLUTION == 1
class Solution {
public:
    int minDistance(string word1, string word2) {
        // word1.size() + word2.size() - 2 * lcs
        const int len1 = word1.size();
        const int len2 = word2.size();
        vector<vector<int> > dp(len1+1, vector<int>(len2+1));
        for (int i = 0; i <= len1; ++i) dp[i][0] = 0;
        for (int j = 0; j <= len2; ++j) dp[0][j] = 0;
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                // update dp[i+1][j+1]
                // dp[i+1][j+1] = dp[i][j] + 1 if word1[i] == word2[j]
                // otherwise, dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])
                dp[i+1][j+1] = (word1[i] == word2[j]) ? dp[i][j] + 1 :
                    max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return len1 + len2 - 2 * dp[len1][len2];
    }
};
#elif SOLUTION == 2

class Solution {
public:
    int minDistance(string word1, string word2) {
        // word1.size() + word2.size() - 2 * lcs
        const int len1 = word1.size();
        const int len2 = word2.size();
        vector<vector<int> > dp(len1+1, vector<int>(len2+1));
        for (int i = 0; i <= len1; ++i) dp[i][0] = i;
        for (int j = 0; j <= len2; ++j) dp[0][j] = j;
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                // update dp[i+1][j+1]
                dp[i+1][j+1] = (word1[i] == word2[j]) ? dp[i][j] :
                    min(dp[i+1][j], dp[i][j+1]) + 1;
            }
        }
        return dp[len1][len2];
    }
};

#elif SOLUTION == 3

class Solution {
public:
    int minDistance(string word1, string word2) {
        // word1.size() + word2.size() - 2 * lcs
        const int len1 = word1.size();
        const int len2 = word2.size();
        vector<vector<int> > dp(2, vector<int>(len2+1));
        for (int j = 0; j <= len2; ++j) dp[0][j] = j;
        bool cur = false;
        for (int i = 0; i < len1; ++i, cur=!cur) {
            dp[!cur][0] = i+1;
            for (int j = 0; j < len2; ++j) {
                // update dp[i+1][j+1]
                dp[!cur][j+1] = (word1[i] == word2[j]) ? dp[cur][j] :
                    min(dp[!cur][j], dp[cur][j+1]) + 1;
            }
        }
        return dp[cur][len2];
    }
};

#endif
