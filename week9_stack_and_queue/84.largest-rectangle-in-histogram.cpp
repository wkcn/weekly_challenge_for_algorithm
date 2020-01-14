#include "common.h"

#define WRONG_SOLUTION 0

#if WRONG_SOLUTION
// 最简单的O(n^2)算法，但是这种方法会超时
class TLESolution {
public:
  int largestRectangleArea(vector<int>& heights) {
    if (heights.empty()) return 0;
    const int len = heights.size();
    int best = 0;
    for (int i = 0; i < len; ++i) {
      int h = heights[i];
      for (int j = i; j >= 0; --j) {
        // 可以优化的地方，比如h的更新，h不变的情况下，左边界越靠近左边越好
        // 样例：3, 4, 10, 8, 20, 8, X
        //       3, 4,  8, 8,  8, 8
        // 所以处理到X时，其实只要保存3, 4, 8
        // 如何能知道h=8时的长度呢，看4的下标
        // 当X > 8时，与3,4,8进行面积计算, 并将8的下标放进栈
        // 当X < 8时，也要与3, 4, 8进行计算，但是原来在栈中的8可以扔掉了
        // 当X = 8时，也要与3, 4, 8进行计算，但是不需要改变栈
        h = min(h, heights[j]);
        int area = h * (i - j + 1);
        best = max(best, area);
      } 
    }
    return best;
  }
};
#endif

class Solution {
// https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28917/AC-Python-clean-solution-using-stack-76ms
public:
  int largestRectangleArea(vector<int>& heights) {
    if (heights.empty()) return 0;
    const int len = heights.size();
    stack<int> st;
    st.push(-1);
    int best = 0; 
    for (int i = 0; i <= len; ++i) {
      const int h = i < len ? heights[i] : 0;
      while (st.top() != -1 && h < heights[st.top()]) {
        int sh = heights[st.top()]; st.pop();
        int w = i - st.top() - 1;
        int area = sh * w;
        best = max(best, area);
      }
      // 即使当前高度和栈顶高度一致，也要将这个数字放进去，如：0,1,0,1
      // 和7,9,7,9有什么区别
      // 0, 1, 0, 1与1, 2, 1, 2
      // TODO: 栈是怎么变的，能不能压缩
      st.push(i);
    }
    return best;
  }
};

int main() {
  vector<int> heights;
  INPUT_ARRAY(heights);
  cout << Solution().largestRectangleArea(heights) << endl;
  return 0;
}
