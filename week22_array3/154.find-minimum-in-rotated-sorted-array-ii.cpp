#include "common.h"

// TODO: 分析多种情况，列出所有可能
//
// 有可能中值与最左边的值相等
//
// -----xxxx------- 
// xxxx可以上升、下降、相等 
#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int findMin(vector<int>& nums) {
        const int len = nums.size();
        if (len <= 0) return 0;
        queue<pair<int, int> > q;
        q.push({0, len});
        int ans = nums[0];
        while (!q.empty()) {
          auto p = q.front(); q.pop();
          int lo = p.first, hi = p.second;
          while (lo < hi) {
              int mid = lo + ((hi - lo) >> 1);
              if (nums[0] == nums[mid]) {
                q.push({lo, mid});
                q.push({mid+1, hi});
                break;
              }
              else nums[0] < nums[mid] ? lo = mid + 1 : hi = mid;
          }
          if (lo < len) {
            ans = min(ans, nums[lo]);
          }
        }
        return ans;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    int findMin(vector<int>& nums) {
        const int len = nums.size();
        if (len <= 0) return 0;
        int lo = 0, hi = len;
        while (lo < hi) {
            int mid = lo + ((hi - lo - 1) >> 1); // 这里是hi - lo - 1, 保证剩余两个元素时，中值在左边(因为要和右边对比)
            if (nums[hi-1] == nums[mid]) --hi; // 针对hi
            else nums[hi-1] < nums[mid] ? lo = mid + 1 : hi = mid + 1; // 注意这里是hi = mid + 1
        }
        return nums[lo];
    }
};
#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().findMin(nums) << endl;
  return 0;
}
