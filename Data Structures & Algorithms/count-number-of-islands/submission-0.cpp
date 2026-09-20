class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if ('1'== grid[row][col]) {
                    count++;
                    markIsland(grid, row, col);
                }
            }
        }
        return count;
    }
    void markIsland(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || col < 0 ||
            grid.size() == row || grid[row].size() == col ||
            '0' == grid[row][col])
        {
            return;
        }
        grid[row][col] = '0';
        markIsland(grid, row - 1, col);
        markIsland(grid, row + 1, col);
        markIsland(grid, row, col - 1);
        markIsland(grid, row, col + 1);
    }
};
