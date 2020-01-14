#include "common.h"

class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    // nums可能是重复的
    const int len = nums.size();
    vector<int> res(len, -1);
    stack<pair<int, int> > st;
    for (int i = 0; i < len; ++i) {
      int &v = nums[i];
      while (!st.empty() && v > st.top().first) {
        res[st.top().second] = v;
        st.pop();
      }
      st.push({v, i});
    }
    for (int i = 0; i < len; ++i) {
      int &v = nums[i];
      while (!st.empty() && v > st.top().first) {
        res[st.top().second] = v;
        st.pop();
      }
    }
    return res;
  }
};

// TODO: 动态规划

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  PRINT_ARRAY(Solution().nextGreaterElements(nums));
  return 0;
}
