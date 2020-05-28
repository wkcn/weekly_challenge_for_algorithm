// [TODO] 好题目!
// reference: https://leetcode-cn.com/problems/count-of-range-sum/solution/327qu-jian-he-de-ge-shu-ti-jie-zong-he-by-xu-yuan-/
// https://leetcode-cn.com/problems/count-of-range-sum/solution/java-yu-shu-zhuang-shu-zu-by-a-12-ca1eae-cae/
// https://www.cnblogs.com/findview/archive/2019/08/01/11281628.html

/*
给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。
区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。

说明:
最直观的算法复杂度是 O(n2) ，请在此基础上优化你的算法。

示例:

输入: nums = [-2,5,-1], lower = -2, upper = 2,
输出: 3 
解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-of-range-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        const int len = nums.size();
        if (len == 0) return 0;
        vector<int64_t> presum(len + 1);
        presum[0] = 0;
        for (int i = 0; i < len; ++i) {
            presum[i + 1] = presum[i] + nums[i];
        }
        int ans = 0;
        multiset<int64_t> se;
        se.insert(0); // presum[0] == 0
        for (int i = 0; i < len; ++i) {
            // find i
            // lower <= p[j] - p[i] <= upper
            // lower + p[i] <= p[j] <= upper + p[i]
            // p[i] <= p[j] - lower
            auto left = se.lower_bound(-upper + presum[i + 1]);
            auto right = se.upper_bound(-lower + presum[i + 1]);
            ans += distance(left, right);
            se.insert(presum[i + 1]);
        }
        return ans;
    }
};
