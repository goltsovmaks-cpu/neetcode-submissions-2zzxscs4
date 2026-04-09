class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix)
        : Matrix_(std::move(matrix))
    {
        // Matrix_ [i][j] = Sum of all elements before (up/left) include this.
        for (size_t row = 0; row < Matrix_.size(); ++row) {
            for (size_t col = 0; col < Matrix_[row].size(); ++col) {
                if (0 != col) {
                    Matrix_[row][col] += Matrix_[row][col-1];
                }
                if (0 != row) {
                    Matrix_[row][col] += Matrix_[row-1][col];
                }
                if (0 != col && 0 != row) {
                    Matrix_[row][col] -= Matrix_[row-1][col-1];
                }
            }
        }
    }
    
    //. A | B
    //  C | D
    // Sum = A + B + C + D => D = SUM  - (A+B)(right up) - (A+C) (left down) + A
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = Matrix_[row2][col2];

        int rightUp = row1 != 0 ? Matrix_[row1 - 1][col2] : 0;  
        int leftDown = col1 != 0 ? Matrix_[row2][col1-1] : 0;

        int leftUp = 0;
        if (0 != row1 && 0!= col1) {
            leftUp = Matrix_[row1-1][col1-1];
        }
        return sum - rightUp - leftDown + leftUp;
    }
private:
    vector<vector<int>> Matrix_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */