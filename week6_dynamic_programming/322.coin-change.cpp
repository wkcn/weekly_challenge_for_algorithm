// TODO: 注意顺序以及拓展到其他题目, 使用排序等方法是否能更快？
#include "common.h"

#define SOLUTION 3

#if SOLUTION == 1
// 向后
// 注意动归的迭代顺序，初值设置，数值是否越界，异常值返回(-1)
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, INT32_MAX);
    // dp[t] = min(dp[t - c[i]]) + 1
    dp[0] = 0;
    for (int a = 0; a < amount; ++a) {
      if (dp[a] == INT32_MAX) continue;
      for (const int &c : coins) {
        // 注意c + a溢出的情况
        if (c <= amount - a) {
          int t = a + c;
          dp[t] = min(dp[t], dp[a] + 1);
        }
      }
    }
    return dp[amount] == INT32_MAX ? -1 : dp[amount];
  }
};
#elif SOLUTION == 2
// 向前
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    // 注意要处理哪些a, 向前还是向后
    for (int a = 1; a <= amount; ++a) {
      for (const int &c : coins) {
        if (a >= c) {
          dp[a] = min(dp[a], dp[a-c]+1);
        }
      }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};
#elif SOLUTION == 3
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    for (const int &c : coins) {
      for (int a = c; a <= amount; ++a) {
        dp[a] = min(dp[a], dp[a-c]+1);
      }
    }
    return dp[amount] > amount ? -1 : dp[amount]; 
  }
};
#endif

int main() {
  vector<int> coins;
  INPUT_ARRAY(coins);
  int amount;
  cin >> amount;
  cout << Solution().coinChange(coins, amount) << endl;
  return 0;
}
