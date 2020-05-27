class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        int cur = nums[0], prev = 0;
        for (int i = 1; i < n - 1; ++i) {
            int tmp = cur;
            cur = max(prev + nums[i], cur);
            prev = tmp;
        }
        int rob0 = cur;
        cur = 0, prev = 0;
        for (int i = 1; i < n; ++i) {
            int tmp = cur;
            cur = max(prev + nums[i], cur);
            prev = tmp;
        }
        return max(rob0, cur);
    }
};
