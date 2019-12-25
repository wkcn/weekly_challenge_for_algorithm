#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  int minDistance(string word1, string word2) {
    const int L1 = word1.size(), L2 = word2.size();
    vector<vector<int> > dp(L1+1, vector<int>(L2+1, L1+L2));
    /*
     * dp[i, j] 代表word1[:i]和word2[:j]的编辑距离
     * 初值
     * dp[0, 0] = 0
     * dp[0, k] = k
     * dp[k, 0] = k
     * 转移方程
     * dp[i+1,j+1] = min{dp[i, j] if word1[i] == word2[j]
     *               otherwise, dp[i+1, j]+1, dp[i, j+1]+1, dp[i,j]+1
     *               分别对应删除和替换
     *               }
     */
    for (int k = 0; k <= L1; ++k) dp[k][0] = k;
    for (int k = 1; k <= L2; ++k) dp[0][k] = k;
    for (int i = 0; i < L1; ++i) {
      for (int j = 0; j < L2; ++j) {
        if (word1[i] == word2[j]) dp[i+1][j+1] = dp[i][j];
        else dp[i+1][j+1] = min(dp[i][j], min(dp[i][j+1], dp[i+1][j]))+1; // 下标变量不要写错
      }
    }
    // PRINT_MATRIX(dp);
    return dp[L1][L2];
  }
};
#elif SOLUTION == 2
class Solution {
public:
  int minDistance(string word1, string word2) {
    const int L1 = word1.size(), L2 = word2.size();
    if (L1 > L2) return minDistance(word2, word1);
    // L1 <= L2
    vector<int> dp(L1+1);
    for (int k = 0; k <= L1; ++k) dp[k] = k;
    for (int j = 0; j < L2; ++j) {
      // 注意压缩DP的覆盖顺序, 以及需要保存哪些状态
      int lt = dp[0];
      dp[0] = j+1;
      for (int i = 0; i < L1; ++i) {
        int old = dp[i+1];
        if (word1[i] == word2[j]) dp[i+1] = lt;
        else dp[i+1] = min(lt, min(dp[i], dp[i+1]))+1;
        lt = old;
      }
    }
    return dp[L1];
  }
};
#endif

int main() {
  string word1, word2;
  cin >> word1 >> word2;
  cout << Solution().minDistance(word1, word2) << endl;
  return 0;
}
