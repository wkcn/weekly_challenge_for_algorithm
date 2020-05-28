class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int best = 0;
        string ans;
        for (string &e : d) {
            if ((e.size() > best || (e.size() == best && e < ans)) && is_valid(s, e)) {
                best = e.size();
                ans = e;
            }
        }
        return ans;
    }
    bool is_valid(string &s, string &e) {
      // 可以交换下循环的顺序，外循环遍历s
        int j = 0;
        // for循环条件里不能加j < s.size()
        for (int i = 0; i < e.size(); ++i) {
            while (j < s.size() && s[j] != e[i]) ++j;
            ++j;
        }
        return j <= s.size();
    }
};
