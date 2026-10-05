class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ROW_COUNT = heights.size();
        int COL_COUNT = heights[0].size();

        vector<vector<bool>> visited(ROW_COUNT, vector<bool>(COL_COUNT, false));
        using TCell = pair<int, int>; // row, coll
        using TItem = pair<int, TCell>; // Effort, point

        priority_queue<TItem, vector<TItem>, greater<TItem>> queue;
        queue.push({0,{0,0}});
        vector<pair<int,int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };
        while (!queue.empty()) {
            
            auto [efford, cell] = queue.top();
            auto [row, col] = cell;
            queue.pop();
            if (row + 1 == ROW_COUNT && col + 1 == COL_COUNT) {
                return efford;
            }

            if (visited[row][col]) {
                continue;
            }
            visited[row][col] = true;

            for (auto [dr, dc]: directions) {
                int newRow = row + dr;
                int newCol = col + dc;
                if (0 <= newRow && newRow < ROW_COUNT &&
                    0 <= newCol && newCol < COL_COUNT &&
                    !visited[newRow][newCol])
                {
                    int maxEfford = max(efford, abs(heights[newRow][newCol] - heights[row][col]));
                    queue.push({maxEfford, {newRow, newCol}});
                }
            }
        }

        return -1;
    }
};















