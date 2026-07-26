class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rowCount = obstacleGrid.size();
        int colCount = obstacleGrid[0].size();
        vector<int> dp(colCount, 0);

        for (int i = 0; i < colCount; i++) {
            if (0 == obstacleGrid[0][i]) {
                dp[i] = 1;
            } else {
                break;
            }
        }

        for (int row = 1; row < rowCount; row++) {
            if (1 == obstacleGrid[row][0]) {
                dp[0] = 0;
            }
            for (int col = 1; col < colCount; col++) {
                if (0 == obstacleGrid[row][col]) {
                    dp[col] += dp[col - 1];
                } else {
                    dp[col] = 0;
                }
            }
        }

        return dp.back();
    }
};