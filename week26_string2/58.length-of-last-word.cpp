class Solution {
public:
    int lengthOfLastWord(string s) {
        // 字符串末尾可能有空格
        // 特殊情况：比如空字符串，" ", "a"
        // [i, j)表示最后一个单词
        int j = s.size();
        while (j > 0 && s[j-1] == ' ') --j;
        // j此时在末尾或指向空格
        int i = j;
        while (i > 0 && s[i-1] != ' ') --i;
        return j - i;
    }
};
