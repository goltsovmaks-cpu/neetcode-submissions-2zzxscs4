class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroRow = ranges::any_of(matrix, [](const auto& row){return 0 == row[0];});
        bool zeroCol = ranges::any_of(matrix[0], [](int x){return 0 == x;});

        for (int row = 1; row < matrix.size(); row++) {
            for (int col = 1; col < matrix[0].size(); col++) {
                if (0 == matrix[row][col]) {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }

        for (int row = 1; row < matrix.size(); row++) {
            if (0 == matrix[row][0]) {
                ranges::fill(matrix[row], 0);
            }
        }

        for (int col = 1; col < matrix[0].size(); col++) {
            if (0 == matrix[0][col]) {
                for (auto& row: matrix) {
                    row[col] = 0;
                }
            }
        }

        if (zeroRow) {
            for (auto& row: matrix) {
                row[0] = 0;
            }
        }
        if (zeroCol) {
            ranges::fill(matrix[0], 0);
        }
    }
};
