#include "common.h"

class Solution {
public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    const int len = A.size();
    int i = 0, j = 1;
    while (true) {
      while (i < len && (A[i] & 1)==0) i += 2; 
      while (j < len && (A[j] & 1)) j += 2; 
      if (i < len && j < len)
        swap(A[i], A[j]);
      else
        break;
    }
    return A;
  }
};

int main() {
  vector<int> A;
  INPUT_ARRAY(A);
  PRINT_ARRAY(Solution().sortArrayByParityII(A));
  return 0;
}
