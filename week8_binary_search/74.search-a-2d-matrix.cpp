#include "common.h"


#define SOLUTION 4

#if SOLUTION == 1
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int row = matrix.size();
    if (row == 0) return false;
    const int col = matrix[0].size();
    if (col == 0) return false;
    int r = row - 1, c = 0;
    while (r >= 0 && c < col) {
      int val = matrix[r][c];
      if (val == target) return true;
      if (val < target) ++c;
      else --r;
    }
    return false;
  }
};
#elif SOLUTION == 2
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int row = matrix.size();
    if (row == 0) return false;
    const int col = matrix[0].size();
    if (col == 0) return false;
    queue<array<int, 4> > q; 
    q.push({0, 0, row, col});
    while (!q.empty()) {
      array<int, 4> e = q.front(); q.pop();
      if (e[0] >= e[2] || e[1] >= e[3]) continue; // 去除无效范围
      int mid_r = e[0] + (e[2] - e[0]) / 2;
      int mid_c = e[1] + (e[3] - e[1]) / 2;
      int mid_v = matrix[mid_r][mid_c];
      if (mid_v == target) return true;
      // center: (mid_r, mid_c)
      if (mid_v < target) {
        q.push({e[0], mid_c+1, mid_r+1, e[3]});
        q.push({mid_r+1, e[1], e[2], mid_c+1});
        q.push({mid_r+1, mid_c+1, e[2], e[3]});
      } else {
        q.push({e[0], mid_c, mid_r, e[3]}); 
        q.push({mid_r, e[1], e[2], mid_c});
        q.push({e[0], e[1], mid_r, mid_c});
      }
    }
    return false;
  }
};
#elif SOLUTION == 3
// The first integer of each row is greater than the last integer of the previous row.
// 因此可以将矩阵转为数组
// O(log(mn))
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int row = matrix.size();
    if (row == 0) return false;
    const int col = matrix[0].size();
    if (col == 0) return false;
    int lo = 0, hi = row * col;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      int val = matrix[mid / col][mid % col];
      if (val == target) return true;
      val < target ? lo = mid + 1 : hi = mid;
    }
    return false;
  }
};
#elif SOLUTION == 4
// O(log(m) + log(n)) = O(log(mn))
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int row = matrix.size();
    if (row == 0) return false;
    const int col = matrix[0].size();
    if (col == 0) return false;
    int lo = 0, hi = row;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      matrix[mid].back() < target ? lo = mid + 1 : hi = mid;
    }
    if (lo >= row) return false;
    if (matrix[lo].back() == target) return true;
    int r = lo;
    lo = 0, hi = col;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      matrix[r][mid] < target ? lo = mid + 1 : hi = mid;
    }
    return lo < col && matrix[r][lo] == target;
  }
};
#endif

int main() {
  vector<vector<int> > mat;
  int target;
  INPUT_ARRAY2D(mat);
  cin >> target;
  cout << Solution().searchMatrix(mat, target);
  return 0;
}
