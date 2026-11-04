class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = r + 1; c < matrix[0].size(); c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }

        for (auto& row: matrix) {
            ranges::reverse(row);
            // int l = 0;
            // int r = row.size() - 1;

            // while (l < r) {
            //     swap(row[l], row[r]);
            //     l++;
            //     r--;
            // }
        }
    }
};
