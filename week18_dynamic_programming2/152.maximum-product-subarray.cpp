class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        const int size = nums.size();
        vector<int> min_arr(size), max_arr(size);
        min_arr[0] = max_arr[0] = nums[0];
        for (int i = 1; i < size; ++i) {
            int x = nums[i];
            int a = min_arr[i-1] * x;
            int b = max_arr[i-1] * x;
            min_arr[i] = min({x, a, b});
            max_arr[i] = max({x, a, b});
            ans = max(max_arr[i], ans);
        }
        return ans;
    }
};
