class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 1 && '0' == num1[0] || 
            num2.size() == 1 && '0' == num2[0])
        {
            return {'0'};
        }
        ranges::reverse(num1);
        ranges::reverse(num2);
        string result;
        for (int i = 0; i < num1.size(); i++) {
            int digit1 = num1[i] - '0';
            int carry = 0;
            for (int j = 0; j < num2.size(); j++) {
                int digit2 = num2[j] - '0';
                int product = digit1 * digit2;

                while (result.size() <= i + j) {
                    result.push_back('0');
                }
                int totalSum = result[i+j] - '0' + product + carry;
                result[i+j] = '0' + (totalSum % 10);
                carry = totalSum / 10;
            }
            if (carry) {
                result.push_back('0' + carry);
            }
        }

        ranges::reverse(result);
        ranges::reverse(num1);
        ranges::reverse(num2);

        return result;
    }
};
