class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> cnts;
        for (char &c : tiles) ++cnts[c];
        int ans = 0;
        function<void()> F;
        F = [&]() {
            for (auto &p : cnts) {
                if (p.second > 0) {
                    --p.second;
                    ++ans;
                    F();
                    ++p.second;
                }
            }
        };
        F();
        return ans;
    }
};
