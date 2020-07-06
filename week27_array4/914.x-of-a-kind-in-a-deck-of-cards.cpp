inline int gcd(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int counts[10000] = {0};
        for (int x : deck) ++counts[x];
        int r = 0;
        for (int i = 0; i < 10000; ++i) {
            if (counts[i] > 0)
                r = gcd(counts[i], r);
        }
        return r >= 2;
    }
};
