class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> queue;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (2 == grid[row][col]) {
                    queue.push({row, col});
                }
            }
        }

        int time = 0; // queue.empty()? / only rotten? 

        auto tryAdd = [&] (int row, int col) {
            if (row < 0 || col < 0 ||
                row >= grid.size() || col >= grid[row].size() ||
                1 != grid[row][col])
            {
                return;
            }
            queue.push({row, col});
            grid[row][col] = 2;
        };
        while (!queue.empty()) {
            int lenght = queue.size();
            for (int i = 0; i < lenght; i++) {
                auto [row, col] = queue.front();
                queue.pop();

                tryAdd(row - 1, col);
                tryAdd(row + 1, col);
                tryAdd(row, col - 1);
                tryAdd(row, col + 1);
            }
            if (!queue.empty()) {
                time++;
            }
        }

        for (auto& row: grid) {
            for (int cell: row) {
                if (1 == cell) {
                    return -1;
                }
            }
        }
        return time;
    }
};
