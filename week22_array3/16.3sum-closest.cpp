// TODO: 一些优化，比如去重，求最值提前终止
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = accumulate(nums.begin(), nums.begin() + 3, 0);
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int su = nums[i] + nums[j] + nums[k];
                int diff = su - target;
                if (abs(ans - target) > abs(diff)) {
                    ans = su;
                }
                if (diff == 0) return ans;
                diff < 0 ? ++j : --k;
            }
        }
        return ans;
    }
};
