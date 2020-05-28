class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int len = position.size();
        vector<int> inds(len);
        for (int i = 0; i < len; ++i) inds[i] = i;
        sort(inds.begin(), inds.end(), [&position](int a, int b) {
            return position[a] > position[b];
        });
        vector<float> cost(len); // 用dis1 * speed2 和 dis2 * speed1 的方法会溢出
        for (int i = 0; i < len; ++i) cost[i] = (target - position[i]) / float(speed[i]);
        int team = 0;
        int i = 0;
        while (i < len) {
            ++team;
            int id = inds[i]; // the leader of team
            int j = i + 1;
            for (;j < len; ++j) {
                int id2 = inds[j];
                if (cost[id] < cost[id2]) {
                    break;
                }
            }
            i = j;
        }
        return team;
    }
};
