class Solution {
public:
    bool isPowerOfFour(int num) {
        // 4: 100
        // 16: 10000
        // 按位与优先级比==低！
        return num > 0 && (num & (num - 1)) == 0 && ((num & 0xaaaaaaaa) == 0);
    }
};
