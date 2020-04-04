class Solution {
public:
    int calculate(string s) {
        // 可以对乘法除法加个括号
        // 3 + 2 * 2 = 3 + (2 * 2)
        int ans = 0;
        int i = 0;
        const int slen = s.size();
        auto read_int = [&]() -> int {
            int v = 0;
            while (i < slen && s[i] == ' ') ++i;
            while (i < slen && isdigit(s[i])) {
                v = v * 10 + (s[i] - '0'); // 注意，加括号后可以避免越界！
                ++i;
            }
            return v;
        };

        int lv = read_int();
        while (i < slen) {
            while (i < slen && s[i] == ' ') ++i;
            if (i >= slen) break;
            char op = s[i++];
            switch (op) {
                case '+':
                    ans += lv;
                    lv = read_int();
                    break;
                case '-':
                    ans += lv;
                    lv = -read_int();
                    break;
                case '*':
                    lv *= read_int(); break;
                case '/':
                    lv /= read_int(); break;
            }
        }
        ans += lv;
        return ans;
    }
};
