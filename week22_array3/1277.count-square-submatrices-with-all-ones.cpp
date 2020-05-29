#include "common.h"

// 可以直接用matrix作为dp?
#define SOLUTION 1

#if SOLUTION == 1

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
      const int row = matrix.size();
      if (row == 0) return 0;
      const int col = matrix[0].size();
      if (col == 0) return 0;
      auto &dp = matrix;
      for (int r = 1; r < row; ++r) {
        for (int c = 1; c < col; ++c) {
          if (matrix[r][c])
            dp[r][c] = min({dp[r-1][c-1], dp[r-1][c], dp[r][c-1]}) + 1;
        }
      }
      int ans = 0;
      for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
          int v = dp[r][c];
          ans += v;
        }
      }
      return ans;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
      const int row = matrix.size();
      if (row == 0) return 0;
      const int col = matrix[0].size();
      if (col == 0) return 0;
      vector<vector<int> > dp(row, vector<int>(col, 0)); 
      dp[0] = matrix[0];
      for (int r = 1; r < row; ++r) {
        dp[r][0] = matrix[r][0];
      }
      for (int r = 1; r < row; ++r) {
        for (int c = 1; c < col; ++c) {
          // 注意条件
          if (matrix[r][c])
            dp[r][c] = min({dp[r-1][c-1], dp[r-1][c], dp[r][c-1]}) + 1;
        }
      }
      int ans = 0;
      for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
          int v = dp[r][c];
          ans += v;
        }
      }
      return ans;
    }
};
#endif

int main() {
  vector<vector<int> > mat;
  INPUT_ARRAY2D(mat);
  cout << Solution().countSquares(mat);
  return 0;
}
