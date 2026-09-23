class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result; 

        auto pacific = DoFlow(heights, 0, 0);
        auto atlantic = DoFlow(heights, heights.size() - 1, heights.back().size() - 1);

        for (int row = 0; row < heights.size(); row++) {
            for (int col = 0; col < heights[row].size(); col++) {
                if (pacific[row][col] && atlantic[row][col]) {
                    result.push_back({row, col});
                }
            }
        }
        return result;
    }

    vector<vector<bool>> DoFlow(const vector<vector<int>>& heights, int rowIdx, int colIdx) {
        vector<vector<bool>> ocean(heights.size(), vector<bool>(heights[0].size(), false));
        queue<pair<int, int>> queue;

        auto tryAdd = [&] (int row, int col, int prev) {
            if (0 <= row && row < heights.size() && 
                0 <= col && col < heights[row].size() &&
                heights[row][col] >= prev && !ocean[row][col])
            {
                queue.push({row, col});
                ocean[row][col] = true;
            }
        };

        for (int col = 0; col < heights[rowIdx].size(); col++) {
            tryAdd(rowIdx, col, 0);
        }
        for (int row = 0; row < heights.size(); row++) {
            tryAdd(row, colIdx, 0);
        }

        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();
            int value = heights[row][col];
            tryAdd(row - 1, col, value);
            tryAdd(row + 1, col, value);
            tryAdd(row, col - 1, value);
            tryAdd(row, col + 1, value);
        }
        return ocean;
    }
};
