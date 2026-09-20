class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int maxArea = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (1 == grid[row][col]) {
                    int area = bfs(grid, row, col);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
    int bfs(vector<vector<int>>& grid, int row, int col)
    {
        int count = 0;
        queue<pair<int,int>> queue;

        auto isWater = [&] (int r, int c) {
            return r < 0 || c < 0 ||
                   r >= grid.size() || c >= grid[r].size() ||
                   0 == grid[r][c];
        };

        auto tryAdd = [&] (int r, int c) {
            if (!isWater(r, c)) {
                queue.push({r, c});
                grid[r][c] = 0;
            }
        };

        tryAdd(row, col);

        while (!queue.empty()) {
            int lenght = queue.size();
            while (lenght) {
                auto [currRow, currCol] = queue.front();
                queue.pop();
                lenght--;
                count++;

                tryAdd(currRow - 1, currCol);
                tryAdd(currRow + 1, currCol);
                tryAdd(currRow, currCol - 1);
                tryAdd(currRow, currCol + 1);
            }
        }
        return count;
    }
};
