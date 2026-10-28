class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string result;
        int lenght = max(a.size(), b.size());
        result.reserve(lenght + 1);

        for (int i = 0; i < lenght; i++) {
            int valA = i >= a.size() ? 0 : a[a.size() -1 - i] - '0';
            int valB = i >= b.size() ? 0 : b[b.size() -1 - i] - '0';

            int sum = carry + valA + valB;
            carry = sum / 2;
            int num = sum % 2;

            result.push_back('0' + num);
        }
        if (carry) {
            result.push_back('1');
        }

        ranges::reverse(result);

        return result;
    }
};