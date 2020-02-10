#include "common.h"

/*
 * 为了避免重复，其实只需要判断再次添加的数字是否和res末尾数字相同
 * 另一种方法是使用unordered_set
 */
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    const int len1 = nums1.size();
    const int len2 = nums2.size();
    if (len1 == 0 || len2 == 0) return {};
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
      if (nums1[i] == nums2[j]) {
        res.push_back(nums1[i]);
        INC(i, nums1, len1);
        INC(j, nums2, len2);
      } else if (nums1[i] < nums2[j]) INC(i, nums1, len1);
      else INC(j, nums2, len2);
    }
    return res;
  }
private:
  inline void INC(int &i, vector<int> &arr, int len) {
    int v = arr[i]; 
    while (i < len && arr[i] == v) ++i;
  }
};

int main() {
  vector<int> nums1, nums2;
  INPUT_ARRAY(nums1);
  INPUT_ARRAY(nums2);
  PRINT_ARRAY(Solution().intersection(nums1, nums2));
  return 0;
}
