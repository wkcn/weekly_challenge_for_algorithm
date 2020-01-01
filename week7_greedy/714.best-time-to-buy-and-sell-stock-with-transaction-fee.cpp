#include "common.h"

// Reference:
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-han-shou-xu-fei-/
// 状态机：
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-2/

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    const int len = prices.size();
    if (len <= 1) return 0;
    vector<int> buy(len, 0), sell(len, 0);
    // buy[i] = max(buy[i-1], sell[i-1] - prices[i])
    // sell[i] = max(sell[i-1], buy[i-1] + prices[i] - fee)
    //
    // buy[i-1] <= buy[i] < sell[i-1]
    // sell[i-1] <= sell[i]
    buy[0] = -prices[0];
    for (int i = 1; i < len; ++i) {
      buy[i] = max(buy[i-1], sell[i-1] - prices[i]);
      sell[i] = max(sell[i-1], buy[i-1] + prices[i] - fee);
    }
    return sell.back();
  }
};
#elif SOLUTION == 2
class Solution {
public:
  // 不会出现同一天买入又卖出的情况，因为这样肯定亏
  int maxProfit(vector<int>& prices, int fee) {
    const int len = prices.size();
    if (len <= 1) return 0;
    int cash = 0, hold = -prices[0];
    for (int i = 1; i < len; ++i) {
      cash = max(cash, hold + prices[i] - fee);
      hold = max(hold, cash - prices[i]);
    }
    return cash;
  }
};
#endif

int main() {
  vector<int> prices;
  int fee;
  INPUT_ARRAY(prices);
  cin >> fee;
  cout << Solution().maxProfit(prices, fee) << endl;
  return 0;
}
