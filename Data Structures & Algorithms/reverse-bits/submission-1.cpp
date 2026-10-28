class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i <= 31; i++) {
            int bit = (n >> i) & 1;
            res = res | (bit << (31 - i));
        }
        // for (int i = 1; i <= 32; i++) {
        //     res = res << 1;
        //     if (n & 1) {
        //         res++;
        //     }
        //     n = n >> 1;
        // }
        return res;
    }
};
