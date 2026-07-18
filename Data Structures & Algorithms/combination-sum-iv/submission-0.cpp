class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for (int i = 0; i < dp.size(); i++) {
            for (int num: nums) {
                int sum = num + i;
                if (sum <= target) {
                    dp[sum]+= dp[i];
                }
            }
        }
        return dp[target];
    }
};