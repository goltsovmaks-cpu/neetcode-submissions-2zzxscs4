class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int prev = 0;
        for (int& col: grid[0]) {
            col +=prev;
            prev = col;
        }
        prev = 0;
        for (auto& row: grid) {
            row[0] += prev;
            prev = row[0];
        }

        int rowCount = grid.size();
        int colCount = grid[0].size();

        for (int row = 1; row < rowCount; row++) {
            for (int col = 1; col < colCount; col++) {
                grid[row][col] += min(grid[row-1][col], grid[row][col-1]); 
            }
        }
        return grid.back().back();
    }
};