#include "common.h"

#define SOLUTION 2

// https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode/

#if SOLUTION == 1
class Solution {
public:
  int candy(vector<int>& ratings) {
    if (ratings.empty()) return 0;
    const int len = ratings.size();
    vector<int> left(len, 1), right(len, 1);
    for (int i = 1; i < len; ++i)
      if (ratings[i-1] < ratings[i]) left[i] = left[i-1] + 1;
    for (int i = len - 2; i >= 0; --i)
      if (ratings[i] > ratings[i+1]) right[i] = right[i+1] + 1; 
    int total = 0;
    for (int i = 0; i < len; ++i) {
      total += max(left[i], right[i]);
    }
    return total;
  }
};
#elif SOLUTION == 2
class Solution {
public:
  int candy(vector<int>& ratings) {
    if (ratings.empty()) return 0;
    const int len = ratings.size();
    vector<int> can(len, 1);
    for (int i = 1; i < len; ++i)
      if (ratings[i-1] < ratings[i]) can[i] = can[i-1] + 1;
    for (int i = len - 2; i >= 0; --i)
      if (ratings[i] > ratings[i+1]) can[i] = max(can[i], can[i+1] + 1); 
    // 如何证明满足左右约束
    int total = 0;
    for (int v : can)
      total += v;
    return total;
  }
};
#elif SOLUTION == 3
class Solution {
public:
  int candy(vector<int>& ratings) {
    if (ratings.empty()) return 0;
    const int len = ratings.size();
    // TODO 山峰山谷方法
  }
};
#endif

int main() {
  vector<int> ratings;
  INPUT_ARRAY(ratings);
  cout << Solution().candy(ratings) << endl;
  return 0;
}
