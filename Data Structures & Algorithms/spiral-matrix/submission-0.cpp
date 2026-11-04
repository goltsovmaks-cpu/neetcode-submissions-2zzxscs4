class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int L = 0;
        int R = matrix[0].size() - 1;
        int T = 0;
        int D = matrix.size() - 1;

        int mSize = matrix.size() * matrix[0].size();
        vector<int> result;
        result.reserve(mSize);

        while (result.size() < mSize) {
            for (int col = L; col <= R; col++) {
                result.push_back(matrix[T][col]);
            }
            for (int row = T+1; row <= D; row++) {
                result.push_back(matrix[row][R]);
            }
            if (T < D) {
                for (int col = R-1; col >= L; col--) {
                    result.push_back(matrix[D][col]);
                }
            }
            if (L < R) {
                for (int row = D-1; row > T; row--) {
                    result.push_back(matrix[row][L]);
                }
            }
            L++;
            R--;
            T++;
            D--;
        }
        return result;
    }
};
