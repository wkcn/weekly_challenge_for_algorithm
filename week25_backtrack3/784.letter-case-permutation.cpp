// 可以用位运算的异或翻转大小写
// 可以用构建法一个个字母生成
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        function<void(int)> F;
        F = [&](int i) {
            if (i >= S.size()) {
                ans.push_back(S);
                return;
            }
            if (isalpha(S[i])) {
                char oldc = S[i];
                char newc = islower(oldc) ? oldc - 'a' + 'A' : oldc - 'A' + 'a';
                S[i] = newc;
                F(i + 1);
                S[i] = oldc;
            }
            F(i + 1);
        };
        F(0);
        return ans;   
    }
};
