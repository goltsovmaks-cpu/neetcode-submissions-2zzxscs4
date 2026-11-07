class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;

        long long power = n;
        power = abs(n);
        double pow = n > 0 ? x : 1/x;
         
        while (power != 0) {
            if (power & 1) {
                result *= pow;
            }
            pow *= pow; 
            power = power >> 1;
        }

        return result;
    }
};
