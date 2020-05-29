// TODO 另一种解法，桶
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int su = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            su += nums[i];
        }
        return su;
    }
};
