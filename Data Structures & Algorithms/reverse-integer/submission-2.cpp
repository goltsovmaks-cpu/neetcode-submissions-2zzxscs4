class Solution {
public:
    int reverse(int x) {
        int result = 0;
        // int multiplier = 1;
        int maxValue = INT_MAX;

        if (x < 0) {
            // multiplier = -1;
            maxValue = INT_MIN;
        }
        
        int digit = 0;
        while (x != 0) {
            if (abs(maxValue / 10) < abs(result)) {
                return 0;
            }
            result = result * 10;
            digit = x % 10;
            if (abs(maxValue - digit) < abs(result)) {
                return 0;
            }
            result +=digit;
            x /= 10;
        }
        return result;
    }
};
