#include "common.h"

// 其实不用记录info的，根据blacklist的下标就知道偏移量了
class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        sort(blacklist.begin(), blacklist.end());
        int left = 0;
        int num = 0;
        // blacklist:
        // 0, 1, (2), 3, (4), 5
        // left num pair
        //    0,  0,init
        //    3,  2,(0, 0)
        //    5,  3,(2, 1)
        //    x,  x,(3, 2)
        for (int &v : blacklist) {
            // right = v
            int si = v - left;
            if (si > 0) {
                info.push_back({num, left - num});
            }
            left = v + 1;
            num += si;
        }
        if (N - left > 0) info.push_back({num, left - num});
        M = N - blacklist.size();
    }

    int pick() {
        int r = rand() % M;
        // 注意区间二分搜索以及自定义函数的参数列表
        // upper_bound和lower_bound的自定义函数参数列表顺序不一样
        auto p = upper_bound(info.begin(), info.end(), r, [](const int &r, const pair<int, int> &y) {
            return r < y.first;
        });
        --p;
        return r + p->second;
    }
private:
    vector<pair<int, int> > info; // a list of (num, offset)
    int M;
};

int main() {
  int N; vector<int> blacklist;
  cin >> N;
  INPUT_ARRAY(blacklist);
  Solution so(N, blacklist);
  for (int t = 0; t < 10; ++t) {
    cout << so.pick() << endl;
  }
  return 0;
}
