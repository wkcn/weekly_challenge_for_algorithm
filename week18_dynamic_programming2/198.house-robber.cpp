class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        vector<int> rob(n), norob(n);
        rob[0] = nums[0];
        norob[0] = 0;
        for (int i = 1; i < n; ++i) {
            norob[i] = max(rob[i-1], norob[i-1]);
            rob[i] = norob[i-1] + nums[i];
        }
        return max(rob.back(), norob.back());
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        int cur = nums[0], prev = 0;
        for (int i = 1; i < n; ++i) {
            int tmp = cur;
            cur = max(prev + nums[i], cur);
            prev = tmp;
        }
        return cur;
    }
};
