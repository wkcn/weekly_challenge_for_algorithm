#include "common.h"

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> gs;
    const int len1 = nums1.size();
    stack<int> st;
    for (int &v : nums2) {
      while (!st.empty() && v > st.top()) {
        gs[st.top()] = v;
        st.pop();
      }
      st.push(v);
    }
    vector<int> res(len1);
    for (int i = 0; i < len1; ++i) {
      int &v = nums1[i];
      if (gs.count(v)) {
        res[i] = gs[v];
      } else res[i] = -1;
    }
    return res;
  }
};

int main() {
  vector<int> nums1, nums2;
  INPUT_ARRAY(nums1);
  INPUT_ARRAY(nums2);
  PRINT_ARRAY(Solution().nextGreaterElement(nums1, nums2));
  return 0;
}
