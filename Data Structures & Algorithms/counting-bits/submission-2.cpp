class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        result.reserve(n);
        result.push_back(0);

        int num = 1;
        int offset = 1;
        while (num <= n) {
            if (offset << 1 == num) {
                offset <<= 1;
            }
            int count = 1 + result[num - offset];
            result.push_back(count);

            num++;
        }
        return result;
    }
};
