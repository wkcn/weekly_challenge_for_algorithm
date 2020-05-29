class Solution {
public:
    string toHex(int num) {
        string ans;
        unsigned int u = num;
        int offset = 32;
        bool first = true;
        do {
            offset -= 4;
            int v = (u >> offset) & 0xF;
            if (!first || v != 0) {
                ans += ma[v];
                first = false;
            }
        } while (offset > 0);
        return ans.empty() ? "0" : ans;
    }
private:
    array<char, 16> ma = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                          'a', 'b', 'c', 'd', 'e', 'f'
    };
};
