class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int result = 1;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >=0; j--) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i]++; // The num itself.
            result = max(result, dp[i]);
        }
        return result;
    }
};
