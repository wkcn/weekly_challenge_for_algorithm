// 好题！
/*
 * 给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。

一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。

返回一对观光景点能取得的最高分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-sightseeing-pair
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        if (A.size() < 2) return 0;
        // 首先A[i]的取值范围很小 1 <= A[i] <= 1000, 可以用hash, bucket
        // (A[i] + A[j] + i - j) = (A[i] + i) + (A[j] - j)
        int pi = A[0];
        int ans = INT32_MIN;
        for (int j = 1; j < A.size(); ++j) {
            ans = max(ans, pi + (A[j] - j));
            pi = max(pi, A[j] + j);
        }
        return ans;
    }
};
