class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        result.reserve(digits.size() + 1);
        int carry = 0;
        int numToAdd = 1;
        for (int i = digits.size() - 1; i >=0; i--) {
            int adder = numToAdd % 10;
            numToAdd /=10;

            int sum = digits[i] + adder + carry;

            carry = sum / 10;
            result.push_back(sum % 10);
        }
        if (carry) {
            result.push_back(carry);
        }
        ranges::reverse(result);
        return result;
    }
};
