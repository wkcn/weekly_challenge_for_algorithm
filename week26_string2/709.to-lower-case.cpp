class Solution {
public:
    string toLowerCase(string str) {
        for_each(str.begin(), str.end(), [](char &c) {
            c |= (0x20);
        });
        return str;
    }
};
