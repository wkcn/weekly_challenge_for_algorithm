// 可以用位运算进行大小写转换
// 可以用迭代方法逐个字符更新
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        const int n = S.size();
        go(ans, S, 0, n);
        return ans;
    }
    void go(vector<string> &ans, string &S, int i, int n) {
        if (i == n) {
            ans.push_back(S);
            return;
        }
        go(ans, S, i+1, n);
        if (islower(S[i])) {
            char old = S[i];
            S[i] = old - 'a' + 'A';
            go(ans, S, i+1, n);
            S[i] = old;
        } else if (isupper(S[i])) {
            char old = S[i];
            S[i] = old - 'A' + 'a';
            go(ans, S, i+1, n);
            S[i] = old;
        }
    }
};
