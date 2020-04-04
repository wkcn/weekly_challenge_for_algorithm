class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;
        queue<string> q;
        q.push(start);
        int step = 0;
        vector<bool> used(bank.size(), false);
        while (!q.empty()) {
            ++step;
            int size = q.size();
            while (size--) {
                string u = q.front(); q.pop();
                for (int j = 0; j < bank.size(); ++j) {
                    if (!used[j] && get_diff(u, bank[j]) == 1) {
                        if (bank[j] == end) return step;
                        used[j] = true;
                        q.push(bank[j]);
                    }
                }
            }
        }
        return -1;
    }
    int get_diff(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) if (a[i] != b[i]) ++diff;
        return diff;
    }
};
