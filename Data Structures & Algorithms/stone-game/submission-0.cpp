class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<int> dp(piles.size(), 0);

        for (int i = piles.size() - 1; i >=0; i--) {
            dp[i] = piles[i];
            for (int j = i+1; j < piles.size(); j++) {
                dp[i] = max(
                    piles[j] - dp[j-1],
                    piles[i] - dp[j]
                );
            }
        }

        return dp.back() > 0;
    }
};