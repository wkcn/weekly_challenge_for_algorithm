#include "common.h"

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
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
        ++i;
        ++j;
      } else if (nums1[i] < nums2[j]) ++i;
      else ++j;
    }
    return res;
  }
};

int main() {
  vector<int> nums1, nums2;
  INPUT_ARRAY(nums1);
  INPUT_ARRAY(nums2);
  PRINT_ARRAY(Solution().intersect(nums1, nums2));
  return 0;
}
