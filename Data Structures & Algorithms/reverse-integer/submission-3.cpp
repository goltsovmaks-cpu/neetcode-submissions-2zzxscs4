class Solution {
public:
    int reverse(int x) {
        int result = 0;
        
        int divLeftOver = x > 0 ? abs(INT_MAX / 10) : abs(INT_MIN / 10); 
        while (x != 0) {
            if (divLeftOver < abs(result)) {
                return 0;
            }
            result = result * 10;

            int digit = x % 10;
            bool upperBound = digit > 0 && x > 0 && abs(INT_MAX - digit) < result;
            bool aboveBound = digit > 0 && x < 0 && abs(INT_MIN - digit) < result;
            if (upperBound || aboveBound) {
                return 0;
            }
            result +=digit;

            x /= 10;
        }
        return result;
    }
};
