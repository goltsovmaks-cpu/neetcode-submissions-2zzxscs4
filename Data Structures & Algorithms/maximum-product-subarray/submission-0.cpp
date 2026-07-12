class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int positive = nums[0];
        int negative = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];

            positive *= num;
            negative *= num;

            int p = positive;
            int n = negative;

            positive = max(max(p, num), n);
            negative = min(min(n, num), p);

            result = max(result, positive);
        }

        return result;

    }
};
