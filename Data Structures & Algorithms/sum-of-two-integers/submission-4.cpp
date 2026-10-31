class Solution {
public:
    int getSum(int a, int b) {
        // int result = a ^ b;
        // int carry = (a & b) << 1;

        // while (carry != 0) {
        //     int tmp = result ^ carry;
        //     carry = (result & carry) << 1;
        //     result = tmp;
        // }

        // return result;



        bool carry = 0;
        stack<bool> st;
        for (int i = 0; i <= 31; i++) {
            bool bitA = a & 1;
            bool bitB = b & 1;

            st.push(bitA ^ bitB ^ carry);
            carry = (bitA && bitB) || (bitB && carry) || (carry && bitA);

            a = a >> 1;
            b = b >> 1;
        }
        int result = 0;
        while (!st.empty()) {
            result = result << 1;
            result += st.top();
            st.pop();
        }

        return result;
    }
};
