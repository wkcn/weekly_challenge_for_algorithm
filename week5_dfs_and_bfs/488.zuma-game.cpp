#include "common.h"

// Naive Method
// RYBGW
int C2I[256];
const char *COLORS = "RYBGW";

class Solution {
public:
  Solution() {
    // 初始化不要放main函数里面！
    for (int i = 0; i < 5; ++i) {
      C2I[COLORS[i]] = i;
    }
  }
  int findMinStep(string board, string hand) {
    board = eliminate(board);
    if (board.empty()) return 0;
    array<int, 5> board_counts{}, hand_counts{};
    for (const char &c : board) {
      ++board_counts[C2I[c]];
    }
    for (const char &c : hand) {
      int i = C2I[c];
      if (board_counts[i] > 0) {
        ++hand_counts[i];
      }
    }
    for (int i = 0; i < 5; ++i) {
      if (board_counts[i] > 0 && board_counts[i] + hand_counts[i] < 3) return -1;
    }
    int min_step = INT32_MAX;
    findMinStepImpl(board, hand_counts, 0, min_step);
    // 注意无解的情况
    return min_step == INT32_MAX ? -1 : min_step;
  }
private:
  void findMinStepImpl(const string &board, array<int, 5> &counts, int step, int &min_step) {
    if (step >= min_step) return;
    if (board.empty()) {
      if (step < min_step) min_step = step;
      return;
    }
    const int len = board.size();
    int i = 0;
    while (i < len) {
      const int start = i;
      const char &c = board[i]; ++i;
      while (i < len && board[i] == c) ++i;
      int cnt = i - start;
      // cnt < 3
      int need = 3 - cnt;
      const int id = C2I[c];
      if (counts[id] >= need) {
        counts[id] -= need;
        const string new_board = get_new_board(board, start, i);
        findMinStepImpl(new_board, counts, step+need, min_step);
        counts[id] += need;
      }
    }
  }
  string get_new_board(const string &board, int start, int end) {
    // [start, end)
    // [0, start) + [end, len)
    return eliminate(board.substr(0, start) + board.substr(end));
  }
  string eliminate(const string &board) {
    const int len = board.size();
    int i = 0;
    while (i < len) {
      const int start = i;
      const char &c = board[i]; ++i;
      while (i < len && board[i] == c) ++i;
      int cnt = i - start;
      if (cnt >= 3) {
        return get_new_board(board, start, i); 
      }
    }
    return board;
  }
};

// TODO: Better method

int main() {
  string board, hand;
  cin >> board >> hand;
  cout << Solution().findMinStep(board, hand) << endl;
  return 0;
}
