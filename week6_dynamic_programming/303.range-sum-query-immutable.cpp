#include "common.h"

class NumArray {
public:
  NumArray(vector<int>& nums) {
    const int len = nums.size();
    su.resize(len + 1);
    su[0] = 0;
    for (int i = 0; i < len; ++i) {
      su[i + 1] = su[i] + nums[i];
    }
  }
  
  int sumRange(int i, int j) {
    // sum(a[i, j)) = sum(a[0, j)) - sum(a[0, i)) 
    // sum(a[i, j]) = sum(a[0, j+1))
    return su[j+1] - su[i];
  }
private:
  vector<int> su; // store [0, i)的和
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  NumArray na(nums);
  while (1) {
    int i, j;
    cin >> i >> j;
    cout << na.sumRange(i, j) << endl;
  }
  return 0;
}
