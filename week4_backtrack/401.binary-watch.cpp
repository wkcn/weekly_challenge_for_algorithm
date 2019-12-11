// 审题，注意不正确的输出，如12:00, 7:90
#include "common.h"

#define SOLUTION 2
#if SOLUTION == 1
class Solution {
public:
  Solution() {
    table.resize(11);
    for (int i = 0; i < (1 << 10); ++i) {
      table[get_num_of_1s(i)].push_back(i);
    }
  }
  vector<string> readBinaryWatch(int num) {
    vector<int> &ta = table[num];
    vector<string> ans;
    for (int t : ta) {
      int hour = t & 0xF;
      if (hour >= 12) continue;
      int minute = t >> 4;
      if (minute >= 60) continue;
      char buf[6];
      sprintf(buf, "%d:%.2d", hour, minute);
      ans.push_back(buf);
    }
    return ans;
  }
private:
  int get_num_of_1s(int u) {
    int c = 0;
    while (u > 0) {
      u &= u - 1;
      ++c;
    }
    return c;
  }
  vector<vector<int> > table;
};
#elif SOLUTION == 2
class Solution {
public:
  vector<string> readBinaryWatch(int num) {
    vector<string> ans;
    for (int hour = 0; hour < 12; ++hour) {
      for (int minute = 0; minute < 60; ++minute) {
        if (bitset<16>(hour << 6 | minute).count() == num)
          ans.push_back(to_string(hour) + (minute < 10 ? ":0" : ":") + to_string(minute));
      }
    }
    return ans;
  }
};
#endif

int main() {
  int num;
  cin >> num;
  for (string &s : Solution().readBinaryWatch(num)) {
    cout << s << endl;
  }
  return 0;
}
