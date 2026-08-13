class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word1.size() + 1);
        iota(dp.rbegin(), dp.rend(), 0);

        for (int i = word2.size() - 1; i >=0; i--) {
            vector<int> temp(word1.size() + 1, 0);
            temp.back() = word2.size() - i;

            for (int j = word1.size() - 1; j >=0; j--) {
                int bestOp = min(temp[j+1], dp[j]); // erase/insert
                bestOp = min(bestOp, dp[j+1]); // replace
                bestOp++; // apply op.

                if (word1[j] == word2[i]) {
                    bestOp = min(bestOp, dp[j+1]);
                }
                temp[j] = bestOp;
            }

            dp = std::move(temp);
        }

        return dp.front();
    }
};
