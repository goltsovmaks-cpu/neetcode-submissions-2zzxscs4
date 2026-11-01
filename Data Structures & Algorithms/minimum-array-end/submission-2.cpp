class Solution {
public:
    long long minEnd(int n, int x) {
        vector<long long> count(64);
        long long curr = 1;
        long long result = x;

        for (int i = 0; i <= 62; i++) {
            long long bit = result & (1L << i);
            if (!bit) {
                curr *=2;
            }
            count[i] = curr;
        }

        for (int i = 62; i >=0; i--) {
            if (result & (1L << i)) {
                continue;
            }

            if (n > count[i] / 2) {
                result |= (1L << i);
                n -= count[i] / 2; // skip all variants with 0 here.
            }
        }

        return result;
    }
};