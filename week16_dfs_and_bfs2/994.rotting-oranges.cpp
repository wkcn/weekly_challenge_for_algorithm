#include "common.h"

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      const int rows = grid.size();
      if (rows == 0) return 0;
      const int cols = grid[0].size();
      if (cols == 0) return 0;
      queue<pair<int, int> > rotted;
      int fresh = 0;
      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          switch (grid[r][c]) {
            case 1:
              ++fresh;
              break;
            case 2:
              rotted.push({r, c});
              break;
          };
        }
      }
      auto rot = [&](unsigned int r, unsigned int c) {
        if (r < rows && c < cols) {
          if (grid[r][c] == 1) {
            --fresh;
            grid[r][c] = 2;
            rotted.push({r, c});
          }
        }
      };
      int minute = 0;
      // 注意！！！这里还需要fresh > 0
      while (!rotted.empty() && fresh > 0) {
        ++minute;
        int size = rotted.size();
        while (size--) {
          auto p = rotted.front(); rotted.pop();
          rot(p.first+1, p.second);
          rot(p.first-1, p.second);
          rot(p.first, p.second+1);
          rot(p.first, p.second-1);
        }
      }
      return fresh > 0 ? -1 : minute;
    }
};
