class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int result = 0;
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(), -1));
        // vector<vector<bool> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[0].size(); col++) {
                result = max(
                    result, 
                    dfs(matrix, -1, row, col, cache));
            }
        }
        return result;
    }

    int dfs(
        const vector<vector<int>>& matrix,
        int prevNum,
        int row, int col,
        vector<vector<int>>& cache)
    {
        if (row < 0 || col < 0 ||
            matrix.size() == row || matrix[0].size() == col)
        {
            return 0;
        }

        int currNum = matrix[row][col];

        if (currNum <= prevNum) {
            return 0;
        }

        if (-1 != cache[row][col]) {
            return cache[row][col];
        }

        int maxPath = 0;
        auto updateMax = [&] (int row, int col) {
            int adjMax = dfs(matrix, currNum, row, col, cache);
            maxPath = max(maxPath, 1 + adjMax);
        };
        updateMax(row - 1, col);
        updateMax(row, col - 1);
        updateMax(row, col + 1);
        updateMax(row + 1, col);

        cache[row][col] = maxPath;
        return maxPath;

    }
};










