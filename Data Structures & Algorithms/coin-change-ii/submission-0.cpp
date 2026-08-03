class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin: coins) {
            for (int sum = 1; sum <= amount; sum++) {
                if (coin <= sum) {
                    dp[sum] += dp[sum - coin];
                }
            }
        }
        return dp[amount];
    }
};
