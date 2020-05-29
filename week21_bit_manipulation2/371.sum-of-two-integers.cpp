class Solution {
public:
    int getSum(int a, int b) {
        unsigned int ua = a, ub = b;
        while (ub > 0) {
            unsigned int oldua = ua;
            ua ^= ub;
            ub &= oldua;
            ub <<= 1;
        }
        return ua;
    }
};
