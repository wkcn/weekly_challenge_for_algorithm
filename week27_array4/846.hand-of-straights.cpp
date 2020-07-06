#include "common.h"

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        // hand: 1, 2, 2, 3, 3, 4, 6, 7, 8
        // cnts: 1, 2, 2, 1, 0, 1, 1, 1
        const int len = hand.size();
        if (len % W) return false;
        sort(hand.begin(), hand.end());
        int i = 0;
        vector<int> cnts;
        while (i < len) {
            int j = i + 1;
            while (j < len && hand[j] == hand[i]) ++j;
            int cnt = j - i;
            cnts.push_back(cnt);
            if (j < len && hand[i] + 1 != hand[j]) {
                // 不连续的情况
                cnts.push_back(0);
            }
            i = j;
        }
        // 对于cnts中的每一个数字，它可能是一个序列的结尾，也有可能是序列的开头或者中间
        vector<int> ends(cnts.size(), 0); // ends[i]表示数字cnts[i]作为结尾的个数
        int mid = 0; // 表示作为中间的数字
        // 好好理解，这里把序列分成了三段，开头，中间，结尾
        for (int i = 0; i < cnts.size(); ++i) {
          if (ends[i] > cnts[i]) return false;
          // ends[i] 其实是包含mid的一部分的
          // 结尾是可以影响mid的
          int head = cnts[i] - mid; // 减去前面的mid, 剩下的作为开头
          if (head > 0) {
            // 当W == 1时，i + W - 1 == i 
            if (i + W - 1 < cnts.size()) ends[i + W - 1] += head;
            else return false;
          } else if (head < 0) return false;
          mid = mid + head - ends[i];  // 先前序列的 + 当前数字 - 所有数字
        }
        return true;
    }
};

int main() {
  vector<int> hand; int W;
  INPUT_ARRAY(hand); cin >> W;
  cout << Solution().isNStraightHand(hand, W) << endl;
  return 0;
}
