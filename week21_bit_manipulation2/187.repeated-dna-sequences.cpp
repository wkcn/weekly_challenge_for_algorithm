class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int len = s.size();
        if (len < 10) return {};
        int seg = 0;
        set<int> vis;
        set<int> res;
        for (int i = 0; i < 10; ++i) {
            int e = get_bit(s[i]);
            seg = (seg << 2) | e;
        }
        vis.insert(seg);
        for (int i = 10; i < len; ++i) {
            int e = get_bit(s[i]);
            seg = ((seg << 2) & 0xFFFFC) | e;
            if (vis.count(seg)) res.insert(seg);
            else vis.insert(seg);
        }
        vector<string> ans;
        for (const int &v : res) {
            ans.emplace_back(to_dna(v));
        }
        return ans;
    }
    int get_bit(char c) {
        switch(c) {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            case 'T':
                return 3;
        }
        return -1;
    }
    string to_dna(int v) {
        int offset = 10 * 2;
        string ans;
        do {
            offset -= 2;
            ans += ma[(v >> offset) & 0x3];
        } while (offset > 0);
        return ans;
    }
private:
    const array<char, 4> ma = {'A', 'C', 'G', 'T'};
};
