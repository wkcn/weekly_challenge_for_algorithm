// NOTICE: 要注意什么时候设标记位
// 可能有两个节点A，B到达同一个节点C，较短的边可能更晚出现，因此C被访问时再标记
// 注意first和second分别是什么！
// TODO: Bellman Ford, Dijkstra, 这两种方法用上额外的dist就可以了，不用加vis数组
#include "common.h"


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int> > > G(N + 1);
        vector<bool> vis(N+1, false);
        for (vector<int> &v : times) {
            G[v[0]].push_back({v[1], v[2]}); // {target, cost}
        }

        // a queue of <time, node_id>
        priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > q;

        int rest = N;
        auto push_node = [&](int k, int t) {
            for (pair<int, int> &p : G[k]) {
                q.push({t + p.second, p.first});
            }
        };
        q.push({0, K});
        int t = 0;
        while (!q.empty()) {
            pair<int, int> p = q.top(); q.pop();
            if (vis[p.second]) continue;
            t = p.first; // priority
            if (--rest == 0) return t;
            push_node(p.second, p.first);
            vis[p.second] = true;
        }
        return -1;
    }
};


int main() {
  vector<vector<int> > times;
  INPUT_ARRAY2D(times);
  int n, k;
  cin >> n >> k;
  cout << Solution().networkDelayTime(times, n, k) << endl;
  return 0;
}
