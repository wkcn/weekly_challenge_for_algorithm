#include "common.h"

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        if (A.empty()) return {};
        sort(A.begin(), A.end());
        vector<int> outs(A.size());
        vector<int> inds(A.size());
        iota(inds.begin(), inds.end(), 0);
        // 要记得排序
        sort(inds.begin(), inds.end(), [&B](int a, int b) {
            return B[a] < B[b];
        });
        int ii = 0;
        int bmi = A.size() - 1; // 指向B的最大值，降序
        for (int i = 0; i < A.size(); ++i) {
            int bi = inds[ii];
            int v = B[bi]; // 从最小到最大
            if (A[i] > v) {
                outs[bi] = A[i];
                ++ii;
            } else {
                // A[i] <= v
                outs[inds[bmi--]] = A[i];
            }
        }
        return outs;
    }
};

int main() {
  vector<int> A, B;
  INPUT_ARRAY(A); INPUT_ARRAY(B);
  PRINT_ARRAY(Solution().advantageCount(A, B));
  return 0;
}
