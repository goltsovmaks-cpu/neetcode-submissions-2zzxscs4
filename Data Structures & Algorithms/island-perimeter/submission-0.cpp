class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        auto isWater = [&] (int row, int col) {
            bool outOfBound = row < 0 || col < 0 ||
                row == grid.size() || col == grid[row].size();
            return outOfBound || 0 == grid[row][col];
        };
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (0 == grid[row][col]) {
                    continue;
                }
                ans += isWater(row-1, col);
                ans += isWater(row+1, col);
                ans += isWater(row, col-1);
                ans += isWater(row, col+1);
            }
        }
        return ans;
    }
};