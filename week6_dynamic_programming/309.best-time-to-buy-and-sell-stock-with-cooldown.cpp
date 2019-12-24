#include "common.h"

#define SOLUTION 1
#if SOLUTION == 1
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // reference: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75927/Share-my-thinking-process
    // buy[i], sell[i], rest[i]
    // buy[i] = max(buy[i-1], rest[i-1]-price);
    // sell[i] = max(sell[i-1], buy[i-1] + price)
    // rest[i] = max(rest[i-1], sell[i-1])
    const int N = prices.size();
    if (N == 0) return 0;
    vector<int> buy(2, 0);
    vector<int> sell(2, 0);
    vector<int> rest(2, 0);
    buy[0] = -prices[0]; // 注意buy的初值！！！
    bool flag = false;
    for (const int &x : prices) {
      buy[!flag] = max(buy[flag], rest[flag]-x);
      sell[!flag] = max(sell[flag], buy[flag]+x);
      rest[!flag] = max(rest[flag], sell[flag]);
      flag = !flag;
      // cout << x << ": " << buy[flag] << ", " << sell[flag] << ", " << rest[flag] << endl;
    }
    return max(buy[flag], max(sell[flag], rest[flag]));
  }
};
#elif SOLUTION == 2
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // TODO: 更好的解法，压缩状态
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75927/Share-my-thinking-process
  }
};
#endif

int main() {
  vector<int> prices;
  INPUT_ARRAY(prices);
  cout << Solution().maxProfit(prices) << endl;
  return 0;
}

