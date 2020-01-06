#include "common.h"

#define SOLUTION 4

#if SOLUTION == 1
// O(n)
// 但是每次都判断了两次==和<
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    const int len = numbers.size();
    if (len <= 1) return {};
    int i = 0, j = len - 1;
    while (i < j) {
      int su = numbers[i] + numbers[j];
      if (su == target) return {i+1, j+1};
      // 不能跳过重复的节点，比如[0, 0, 3, 4], target=0
      if (su < target) ++i;
      else --j;
    }
    return {};
  }
};
#elif SOLUTION == 2
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    const int len = numbers.size();
    if (len <= 1) return {};
    int i = 0, j = len - 1;
    while (i < j) {
      while (i < j && numbers[i] + numbers[j] < target) ++i;
      if (numbers[i] + numbers[j] == target) return {i+1, j+1};
      --j;
    }
    return {};
  }
};
#elif SOLUTION == 3
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    const int len = numbers.size();
    if (len <= 1) return {};
    int i = 0, j = len - 1;
    while (i < j) {
      int su = numbers[i] + numbers[j];
      if (su == target) return {i + 1, j + 1};
      int mid = i + (j - i) / 2;
      int v = numbers[mid];
      int left = numbers[i] + v; 
      // left <= numbers[i] + numbers[j] 
      //
      // if left < target
      // 
      // if left > target
      //   ->   
      //     numbers[i] + numbers[j] >= left > target
      //   j = mid - 1
      // if left == target
      //   return {i+1, mid+1};
      if (left == target) return {i + 1, mid + 1};
      else if (left > target) {
        j = mid - 1;
      } else {
        int right = numbers[j] + v; 
        if (right == target) return {mid + 1, j + 1};
        else if (right < target) {
          i = mid + 1;
        } else {
          if (su < target) ++i;
          else --j;
        }
      }
    }
    return {};
  }
};
#elif SOLUTION == 4
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    const int len = numbers.size();
    if (len <= 1) return {};
    int i = 0, j = len - 1;
    while (i < j) {
      int su = numbers[i] + numbers[j];
      if (su == target) return {i+1, j+1};
      if (su < target) {
        // i = the_first_left_pos(x >= target - numbers[j])
        i = lower_bound(numbers.begin() + i + 1, numbers.begin() + j, target - numbers[j]) - numbers.begin(); 
      } else {
        // j = the_first_right_pos(x <= target - numbers[i])
        j = upper_bound(numbers.begin() + i + 1, numbers.begin() + j, target - numbers[i]) - numbers.begin() - 1;
      }
    }
    return {};
  }
};
#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  int target;
  cin >> target;
  PRINT_ARRAY(Solution().twoSum(nums, target));
  return 0;
}
