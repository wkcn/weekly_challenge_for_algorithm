#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    const int len = prices.size();
    int profit = 0;
    for (int i = 0; i < len - 1; ++i) {
      if (prices[i] < prices[i+1]) {
        profit += prices[i+1] - prices[i];
      }
    }
    return profit;
  }
};
#elif SOLUTION == 2
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    const int len = prices.size();
    int profit = 0;
    int i = 0;
    while (i < len - 1) {
      while (i < len - 1 && prices[i] >= prices[i+1]) ++i;
      int buy = prices[i];
      while (i < len - 1 && prices[i] <= prices[i+1]) ++i;
      int sell = prices[i];
      profit += sell - buy;
    }
    return profit;
  }
};
#endif

int main() {
  vector<int> prices;
  INPUT_ARRAY(prices);
  cout << Solution().maxProfit(prices) << endl;
  return 0;
}
