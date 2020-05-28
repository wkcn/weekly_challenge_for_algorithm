class Solution {
public:
    Solution() {
        for (int i = 0; i <= 10000; ++i) {
            cnts[i] = get_num_1(i);
        }
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int> > bucket(32);
        for (int &v : arr) {
            bucket[cnts[v]].push_back(v);
        }
        vector<int> ans;
        for (int i = 0; i < 32; ++i) {
            sort(bucket[i].begin(), bucket[i].end());
            ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
        }
        return ans;
    }
    int get_num_1(int v) {
        int t = 0;
        while (v > 0) {
            ++t;
            v &= v - 1;
        }
        return t;
    }
private:
    array<int, 10001> cnts;
};
