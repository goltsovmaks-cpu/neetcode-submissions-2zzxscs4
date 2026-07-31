class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if (1 == stones.size()) {
            return stones[0];
        }

        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;

        vector<bool> dp(target + 1, 0);
        dp[0] = true;
        for (int stone: stones) {
            for (int i = dp.size() - 1; i >=0; i--) {
                int prev = i - stone;
                if (prev >=0 && dp[prev]) {
                    dp[i] = true;
                }
            }
        }


        for (int i = dp.size() - 1; i>=0; i--) {
            if (dp[i]) {
                return (sum - i) - i;
            }
        }
        return -1; // unreachable
    }
};