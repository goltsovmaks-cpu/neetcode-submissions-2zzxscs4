class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<optional<int>>> cache(
            ROWS,
                vector<optional<int>>(COLS)
        );
        
        using TCoord = pair<int, int>; // row/col
        using T = pair<int, TCoord>; // weight, cell
        priority_queue<T, vector<T>, std::greater<T>> queue;

        auto tryAdd = [&] (int row, int col, int prewW) {
            if (0 <= row && row < ROWS &&
                0 <= col && col < COLS &&
                !cache[row][col].has_value())
            {
                int worst = max(prewW, grid[row][col]);
                queue.push({worst, {row, col}});
            }
        };

        tryAdd(0, 0, -1);

        while (!queue.empty()) {
            auto [w, cell] = queue.top();
            queue.pop();
            if (cell.first + 1 == ROWS and cell.second + 1 == COLS) {
                return w;
            }
            
            auto [row, col] = cell;
            if (cache[row][col].has_value()) {
                continue;
            }
            cache[row][col] = w;

            tryAdd(row + 1, col, w);
            tryAdd(row - 1, col, w);
            tryAdd(row, col + 1, w);
            tryAdd(row, col - 1, w);
        }

        return -1;
    }
};
