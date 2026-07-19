class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 1; i <=n; i++) {
            for (int delta = 1; delta < i; delta++) {
                int leftOver = i - delta;
                dp[i] = max(dp[i], dp[leftOver] * delta);
                dp[i] = max(dp[i], delta * leftOver);
            }
        }
        return dp[n];
    }
};