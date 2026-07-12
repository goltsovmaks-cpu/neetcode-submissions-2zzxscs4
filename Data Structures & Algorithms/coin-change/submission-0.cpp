class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (0 == amount) {
            return 0;
        }
        vector<int> dp(amount, 0);
        dp[0] = -1;

        for (int i = amount - 1; i >=0; i--) {
            for (int coin: coins) {
                int sum = i + coin;
                if (amount == sum) {
                    dp[i] = 1;
                    break;
                } else if (sum > amount) {
                    continue;
                } else if (dp[sum]) {
                    int currentBestCount = 1 + dp[sum];
                    dp[i] = dp[i] > 0 ? min(dp[i], currentBestCount) : currentBestCount;
                }
            }
        }

        return dp.front();
    }
};
