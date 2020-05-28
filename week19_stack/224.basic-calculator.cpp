#include "common.h"

// 有更简单的写法
class Solution {
public:
    int calculate(string s) {
        const int len = s.size();
        if (len == 0) return 0;
        int p = 0;
        stack<int> nums;
        stack<char> ops;
        auto skip_space = [&] {
            while (p < len && s[p] == ' ') ++p;
        };
        auto get_digit = [&] {
            //skip_space();
            int start = p;
            while (p < len && isdigit(s[p])) ++p;
            return stoi(s.substr(start, p - start));
        };
        auto get_op = [&] {
            //skip_space();
            // if (p >= len) return '\0';
            return s[p++];
        };
        auto check_type = [&] {
            skip_space();
            if (p >= len) return -1;
            if (isdigit(s[p])) return 1;
            return 2;
        };
        auto run_op = [&] {
            while (!ops.empty() && ops.top() != '(') {
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                char sop = ops.top(); ops.pop();
                if (sop == '+') {
                    nums.push(a + b);
                } else nums.push(a - b);
            }
        };
        while (p < len) {
            int type = check_type();
            if (type == -1) break;
            if (type == 1) {
                // digit
                nums.push(get_digit());
            } else {
                // op
                char op = get_op();
                if (op == '(') ops.push(op);
                else {
                    // + or - or )
                    run_op();
                    // 注意这里对右括号的处理
                    if (op == ')') ops.pop();
                    else ops.push(op);
                }
            }
        }
        // 结束时也要处理
        run_op();
        return nums.empty() ? 0 : nums.top();
    }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().calculate(s) << endl;
  return 0;
}
