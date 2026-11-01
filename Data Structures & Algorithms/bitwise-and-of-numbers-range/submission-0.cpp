class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = 0;
        for (int i = 30; i>=0; i--) {
            int bit = 1 << i;
            int L = result + bit;
            int R = result + bit - 1 + bit;

            if (L <= left && right <= R) {
                result = L;
            }
        }
        return result;
    }
};