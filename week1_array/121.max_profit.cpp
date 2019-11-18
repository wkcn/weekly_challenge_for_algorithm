#include "common.h"

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len < 2) return 0;
    int minv = prices[0];
    int res = 0;
    for (int i = 1; i < len; ++i) {
      int &p = prices[i];
      if (p < minv) minv = p;
      else {
        int profit = p - minv;
        if (profit > res) res = profit;
      }
    }
    return res;
  }
};

int main() {
  vector<int> prices;
  INPUT_ARRAY(prices);
  cout << Solution().maxProfit(prices) << endl;
  return 0;
}
