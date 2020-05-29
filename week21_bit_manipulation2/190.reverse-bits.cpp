// 移动数字而不是指针，可能更好
// TODO: 不使用循环的分治方法：32 -> 16 -> 8 -> 4 -> 2 -> 1!!!
inline uint8_t get_rb(uint8_t v) {
    int t = 0;
    int i = 1 << 7, j = 1;
    while (i > 0) {
        if (v & j) t |= i;
        i >>= 1;
        j <<= 1;
    }
    return t;
}

class Solution {
public:
    Solution() {
        for (int i = 0; i < 256; ++i) {
            ma[i] = get_rb(i);
        }
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t v = 0;
        v |= ma[(n & 0xFF)] << 24;
        v |= ma[(n & 0xFF00) >> 8] << 16;
        v |= ma[(n & 0xFF0000) >> 16] << 8;
        v |= ma[(n & 0xFF000000) >> 24];
        return v;
    }
private:
    array<uint8_t, 256> ma;
};
