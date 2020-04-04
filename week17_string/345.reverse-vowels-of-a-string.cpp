class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !is_vowel(s[i])) ++i;
            while (i < j && !is_vowel(s[j])) --j;
            if (i < j) swap(s[i], s[j]);
            ++i; --j;
        }
        return s;
    }
    bool is_vowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
        }
        return false;
    }
};
