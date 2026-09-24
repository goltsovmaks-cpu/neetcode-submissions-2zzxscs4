class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();

        queue<pair<int, int>> queue;

        auto tryAdd = [&] (int row, int col) {
            if (0 <= row && row < ROWS &&
                0 <= col && col < COLS &&
                'O' == board[row][col])
            {
                queue.push({row, col});
                board[row][col] = 'P';
            }
        };
        for (int col = 0; col < COLS; col++) {
            tryAdd(0, col);
            tryAdd(ROWS-1, col);
        }
        for (int row = 0; row < ROWS; row++) {
            tryAdd(row, 0);
            tryAdd(row, COLS - 1);
        }

        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();
            tryAdd(row - 1, col);
            tryAdd(row + 1, col);
            tryAdd(row, col - 1);
            tryAdd(row, col + 1);
        }

        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if ('P' == board[row][col]) {
                    board[row][col] = 'O';
                } else {
                    board[row][col] = 'X';
                } 
            }
        }
    }
};
