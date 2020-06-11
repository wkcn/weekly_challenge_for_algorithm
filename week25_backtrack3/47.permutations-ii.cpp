// 回溯用计数方法或不使用计数方法 
// 迭代
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        ans.push_back(nums);
        while (1) {
            int i;
            for (i = n - 1; i >= 1; --i) {
                if (nums[i-1] < nums[i]) {
                    break;
                }
            }
            if (i == 0) break;
            auto p = upper_bound(nums.rbegin(), nums.rbegin() + (n - i), nums[i-1]);
            swap(*p, nums[i-1]);
            reverse(nums.rbegin(), nums.rbegin() + (n - i));
            ans.push_back(nums);
        }
        return ans;
    }
};

// 递归，回溯
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int &v : nums) ++cnts[v];
        const int n = nums.size();
        vector<int> buf(n);
        vector<vector<int> > ans;
        function<void(int)> F;
        F = [&](int i) {
            if (i >= n) {
                ans.push_back(buf);
                return;
            }
            for (auto &p : cnts) {
                if (p.second > 0) {
                    --p.second;
                    buf[i] = p.first;
                    F(i + 1);
                    ++p.second;
                }
            }
        };
        F(0);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return {};
        sort(nums.begin(), nums.end());
        vector<int> buf(n);
        vector<bool> used(n, false);
        vector<vector<int> > ans;
        function<void(int)> F;
        F = [&](int i) {
            if (i >= n) {
                ans.push_back(buf);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (used[j]) continue;
                if (j > 0 && nums[j-1] == nums[j] && !used[j-1]) continue;
                used[j] = true;
                buf[i] = nums[j];
                F(i + 1);
                used[j] = false;
            }
        };
        F(0);
        return ans;
    }
};
