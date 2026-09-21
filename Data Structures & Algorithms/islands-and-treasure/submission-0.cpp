class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // bfs, spread from chest cells.
        queue<pair<int,int>> queue;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (0 == grid[row][col]) {
                    queue.push({row, col});
                }
            }
        }

        auto isUnvisitedLand = [&] (int row, int col) {
            return row >= 0 && col >= 0 &&
                   row < grid.size() && col < grid[row].size() &&
                   numeric_limits<int>::max() == grid[row][col]; 
        };
        auto tryAdd = [&] (int row, int col, int val) {
            if (isUnvisitedLand(row, col)) {
                grid[row][col] = val;
                queue.push({row, col});
            }
        };

        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();
            int adjVal = grid[row][col] + 1;

            tryAdd(row + 1, col, adjVal);
            tryAdd(row - 1, col, adjVal);
            tryAdd(row, col + 1, adjVal);
            tryAdd(row, col - 1, adjVal);
        }
    }
};
