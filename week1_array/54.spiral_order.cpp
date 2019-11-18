#include "common.h"

const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size();
    if (!row) return {};
    int col = matrix[0].size();
    if (!col) return {};
    int num_steps = row * col;
    int d = 0;
    int r = 0, c = -1;
    int steps[4] = {col, row-1, col-1, row-2};
    vector<int> res;
    while (num_steps > 0) {
      int &s = steps[d];
      for (int i = 0; i < s; ++i) {
        r += dir[d][0];
        c += dir[d][1];
        res.push_back(matrix[r][c]);
      }
      num_steps -= s;
      s -= 2;
      d = (d + 1) % 4;
    }
    return res;
  }
};

int main() {
  vector<vector<int> > matrix;
  INPUT_ARRAY2D(matrix);
  PRINT_ARRAY(Solution().spiralOrder(matrix));
  return 0;
}
