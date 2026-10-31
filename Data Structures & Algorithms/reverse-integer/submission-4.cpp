class Solution {
public:
    int reverse(int x) {
        int result = 0;

        int maxDigit = INT_MAX % 10;
        int minDigit = INT_MIN % 10;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (result > INT_MAX / 10 ||
                INT_MAX / 10 == result && digit > maxDigit)
            {
                return 0;
            }

            if (result < INT_MIN / 10 ||
                INT_MIN / 10 == result && digit < minDigit)
            {
                return 0;
            }

            result = result * 10;
            result +=digit;
        }
        return result;
    }
};
