class Solution {
public:
    bool detectCapitalUse(string word) {
      if (word.size() <= 1) return true;
      char c = word[0];
      char t = word[1];
      if (islower(c) || islower(t)) {
        for (int i = 1; i < word.size(); ++i) {
          if (isupper(word[i])) return false;
        }
      } else {
        for (int i = 1; i < word.size(); ++i) {
          if (islower(word[i])) return false;
        }
      }
      return true;
    }
};
