#include "common.h"

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    if (!row) return 0;
    int col = grid[0].size();
    if (!col) return 0;
    vector<int> dp(col);
    dp[0] = grid[0][0];
    for (int i = 1; i < col; ++i) {
      dp[i] = dp[i - 1] + grid[0][i];
    }
    for (int r = 1; r < row; ++r) {
      dp[0] += grid[r][0];
      for (int c = 1; c < col; ++c) {
        // dp[r][c-1], dp[r-1][c]
        dp[c] = min(dp[c-1], dp[c]) + grid[r][c];
      }
    }
    return dp[col-1];
  }
};

int main() {
  vector<vector<int> > grid;
  INPUT_ARRAY2D(grid);
  cout << Solution().minPathSum(grid) << endl;
  return 0;
}
