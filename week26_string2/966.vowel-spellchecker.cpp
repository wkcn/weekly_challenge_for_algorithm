class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> words; // 完全匹配
        map<string, string> lowups; // 大小写
        map<string, string> vowels; // 元音
        for (const string &s : wordlist) {
            words.insert(s);
            string lu = s;
            for (char &c : lu) c = tolower(c);
            if (!lowups.count(lu)) lowups[lu] = s;
            for (char &c : lu) if (isvowel(c)) c = '#';
            if (!vowels.count(lu)) vowels[lu] = s;
        }
        vector<string> outs;
        for (string &s : queries) {
            if (words.count(s)) outs.push_back(s);
            else {
                for (char &c : s) c = tolower(c);
                if (lowups.count(s)) outs.push_back(lowups[s]);
                else {
                    for (char &c : s) if (isvowel(c)) c = '#';
                    if (vowels.count(s)) outs.push_back(vowels[s]);
                    else outs.push_back({});
                }
            }
        }
        return outs;
    }
    inline bool isvowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }
        return false;
    }
};
