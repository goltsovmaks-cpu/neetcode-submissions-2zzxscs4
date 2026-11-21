class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int down = matrix.size();
        int left = 0;
        int right = matrix[0].size();

        vector<int> result;
        while (result.size() < matrix.size() * matrix[0].size()) {
            // go left;
            for (int col = left; col < right; col++) {
                result.push_back(matrix[top][col]);
            }
            top++;

            // go down
            right--;
            for (int row = top; row < down; row++) {
                result.push_back(matrix[row][right]);
            }
            
            // go left
            down--;
            if (top <= down) { // do not go same row
                for (int col = right - 1; col >= left; col--) {
                    result.push_back(matrix[down][col]);
                }
            }

            if (left < right) {
                for (int row = down - 1; row >= top; row--) {
                    result.push_back(matrix[row][left]);
                }
            }
            left++;
        }

        return result;
    }
    // vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //     int L = 0;
    //     int R = matrix[0].size() - 1;
    //     int T = 0;
    //     int D = matrix.size() - 1;

    //     int mSize = matrix.size() * matrix[0].size();
    //     vector<int> result;
    //     result.reserve(mSize);

    //     while (result.size() < mSize) {
    //         for (int col = L; col <= R; col++) {
    //             result.push_back(matrix[T][col]);
    //         }
    //         for (int row = T+1; row <= D; row++) {
    //             result.push_back(matrix[row][R]);
    //         }
    //         if (T < D) {
    //             for (int col = R-1; col >= L; col--) {
    //                 result.push_back(matrix[D][col]);
    //             }
    //         }
    //         if (L < R) {
    //             for (int row = D-1; row > T; row--) {
    //                 result.push_back(matrix[row][L]);
    //             }
    //         }
    //         L++;
    //         R--;
    //         T++;
    //         D--;
    //     }
    //     return result;
    // }
};
