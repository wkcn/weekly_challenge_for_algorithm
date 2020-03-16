// 其他解法：回溯https://leetcode.com/problems/gray-code/discuss/29880/Backtracking-C%2B%2B-solution
// 公式i ^ (i >> 1)：https://leetcode.com/problems/gray-code/discuss/29881/An-accepted-three-line-solution-in-JAVA
#if SOLUTION == 1

// reference: https://blog.csdn.net/wccchangchun/article/details/51873933
/*
 *    第一步，改变最右边的位元值；
      第二步，改变右边起第一个为1的位元的左边的位元；
      第三步，重复第一步和第二步，直到所有的格雷码产生完毕
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n <= 0) return {0};
        int c = 1 << (n-1);
        vector<int> ans;
        int v = 0;
        for (int i = 0; i < c; ++i) {
            ans.push_back(v);
            v ^= 1;
            ans.push_back(v);
            int m = v & (-v);
            v ^= m << 1;
        }
        return ans;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n <= 0) return {0};
        vector<int> ans(1, 0);
        /*
         * 0000
         * 0001
         * 0011
         * 0010
         * 0110
         * 0111
         * 0101
         * 0100
         */
        for (int i = 0; i < n; ++i) {
          int size = ans.size();
          for (int j = size-1; j >= 0; --j) {
            ans.push_back(ans[j] | (1 << i));
          }
        }
        return ans;
    }
};

#endif
