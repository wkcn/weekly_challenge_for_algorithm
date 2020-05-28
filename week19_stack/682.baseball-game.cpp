class Solution {
public:
    int calPoints(vector<string>& ops) {
        int st[1001]; int st_i = 0;
        int ans = 0;
        for (string &s : ops) {
            if (s[0] == 'C') {
                ans -= st[--st_i];
            } else {
                int score;
                if (s[0] == '+') {
                    score = st[st_i-1] + st[st_i-2];
                } else if (s[0] == 'D') {
                    score = st[st_i-1] * 2; // 有可能是负数，就不要移位了
                } else {
                    score = stoi(s);
                } 
                st[st_i++] = score;
                ans += score;
            }
        }
        return ans;
    }
};
