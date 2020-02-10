#include "common.h"

template <typename IT>
void my_nth_element(IT first, IT nth, IT last) {
  auto f = first;
  while (last - first > 1) {
    IT i = first, j = last - 1;
    auto val = *i;
    while (i < j) {
      while (i < j && *j >= val) --j; 
      *i = *j;
      while (i < j && *i <= val) ++i;
      *j = *i;
    }
    // i == j
    *i = val;
    if (i == nth) return;
    if (i < nth) {
      first = i + 1;
    } else {
      last = i;
    }
  }
}

#define A(i) (nums[(i<<1) % (len & (-2))])

class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    const int len = nums.size();
    if (len <= 1) return;
    auto mid_it = nums.begin() + (len - 1) / 2; 
    my_nth_element(nums.begin(), mid_it, nums.end());
    int val = *mid_it;
    // 使用快排的方法能够使与val相等的数汇聚在中间
    int i = 0, j = len - 1;
    while (i < j) {
      cout << i << ", " << j << endl;
      while (i < j && A(j) > val) --j;
      A(i) = A(j);
      while (i < j && A(i) < val) ++i;
      A(j) = A(i);
    }
    A(i) = val; 
  }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  Solution().wiggleSort(nums);
  PRINT_ARRAY(nums);
  return 0;
}
