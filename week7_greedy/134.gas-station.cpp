#include "common.h"

// TODO: 这题的反证法很有意思：https://leetcode-cn.com/problems/gas-station/solution/jia-you-zhan-by-leetcode/
class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    const int len = gas.size();
    if (len <= 0) return 0;
    int total_tank = 0, cur_tank = 0;
    int start = 0;
    for (int i = 0; i < len; ++i) {
      int diff = gas[i] - cost[i];
      total_tank += diff;
      cur_tank += diff;
      if (cur_tank < 0) {
        start = i + 1;
        cur_tank = 0;
      }
    }
    return total_tank >= 0 ? start : -1;
  }
};

int main() {
  vector<int> gas, cost;
  INPUT_ARRAY(gas);
  INPUT_ARRAY(cost);
  cout << Solution().canCompleteCircuit(gas, cost) << endl;
  return 0;
}
