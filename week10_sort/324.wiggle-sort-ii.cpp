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

#define IND_MAP(i) ((1 + (i << 1)) % (len | 1))
#define A(i) (nums[IND_MAP(i)])

class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    const int len = nums.size();
    if (len <= 1) return;
    // 改成 nums.begin() + len / 2也行
    auto mid_it = nums.begin() + (len - 1) / 2; 
    my_nth_element(nums.begin(), mid_it, nums.end());
    int mid = *mid_it;
    int i = 0, j = len - 1;
    int r = 0;
    // reference: 75. Sort Colors
    while (r <= j) {
      if (A(r) > mid) {
        swap(A(r++), A(i++));
      } else if (A(r) == mid) {
        ++r;
      } else {
        swap(A(r), A(j--));
      } 
    }
  }
};

int main() {

/*
  i  : 0, 1, 2, 3, 4, 5
 A(i): 0, 2, 4, 1, 3, 5

 len is even
 (i << 1) % (len-1) if i == len - 1
 NOTICE: 5

  i  : 0, 1, 2, 3, 4
 A(i): 0, 2, 4, 1, 3

 (i << 1) % len

 上面的排序太复杂了，难实现
 换种编码
  i  : 0, 1, 2, 3, 4, 5
 A(i): 1, 3, 5, 0, 2, 4 

 len is even
 (1 + i * 2) % (len + 1)

  i  : 0, 1, 2, 3, 4
 A(i): 1, 3, 0, 2, 4

 len is odd
 (1 + i * 2) % len

 */
  int len = 6;
  cout << "==len: " << len << endl;
  for (int i = 0; i < len; ++i) {
    cout << IND_MAP(i) << endl;
  }
  len = 5;
  cout << "==len: " << len << endl;
  for (int i = 0; i < len; ++i) {
    cout << IND_MAP(i) << endl;
  }

  vector<int> nums;
  INPUT_ARRAY(nums);
  Solution().wiggleSort(nums);
  PRINT_ARRAY(nums);
  return 0;
}
