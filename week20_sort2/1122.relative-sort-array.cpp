class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> ma;
        for (int i = 0; i < arr2.size(); ++i) {
            ma[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&ma](int &a, int &b) {
            auto pa = ma.find(a);
            bool va = pa != ma.end();
            auto pb = ma.find(b);
            bool vb = pb != ma.end();
            if (va && vb) {
                return pa->second < pb->second;
            } else if (va) {
                return true;
            } else if (vb) {
                return false;
            }
            return a < b;
        });
        return arr1;
    }
};

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> bucket(1001, 0);
        for (int &x : arr1) {
            ++bucket[x];
        }
        vector<int> ans;
        for (int &x : arr2) {
            while (bucket[x]-- > 0) {
                ans.push_back(x);
            }
        }
        for (int i = 0; i <= 1000; ++i) {
            while (bucket[i]-- > 0) ans.push_back(i);
        }
        return ans;
    }
};
