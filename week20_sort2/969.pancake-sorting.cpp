#include "common.h"

// 注意begin和end的设置
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int len = A.size();
        vector<int> res;
        for (int i = len - 1; i >= 1; --i) {
            // 下面两行可以合并
            if (A[i] == i + 1) continue;
            // 找与i+1相等的位置就行了，不用最大值
            auto p = max_element(A.begin(), A.begin() + i + 1);
            if (p != A.begin()) {
                res.push_back(p - A.begin() + 1);
                reverse(A.begin(), p + 1);
            }
            res.push_back(i + 1);
            reverse(A.begin(), A.begin() + i + 1);
        }
        return res;
    }
};

int main() {
  vector<int> A;
  INPUT_ARRAY(A);
  PRINT_ARRAY(Solution().pancakeSort(A));
  return 0;
}
