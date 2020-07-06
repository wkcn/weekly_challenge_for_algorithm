#include "common.h"

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // 将cardPoints的首尾连接起来，比如左边取d个，右边就取k - d个，是一个滑动窗口
        int score = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int best = score;
        int left = k - 1, right = cardPoints.size() - 1;
        while (left >= 0) {
            score += -cardPoints[left--] + cardPoints[right--];
            best = max(best, score);
        }
        return best;
    }
};

int main() {
  vector<int> cardPoints; int k;
  INPUT_ARRAY(cardPoints); cin >> k;
  cout << Solution().maxScore(cardPoints, k) << endl;
  return 0;
}
