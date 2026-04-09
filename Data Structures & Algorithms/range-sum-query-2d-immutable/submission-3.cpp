class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        Matrix_ = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size()+ 1, 0));
        // Matrix_ [i][j] = Sum of all elements before (up/left) include this.
        for (size_t row = 1; row < Matrix_.size(); ++row) {
            for (size_t col = 1; col < Matrix_[row].size(); ++col) {
                Matrix_[row][col] =  
                    matrix[row-1][col-1] +
                    Matrix_[row][col-1] +
                    Matrix_[row-1][col] -
                    Matrix_[row-1][col-1];
            }
        }
    }
    
    //. A | B
    //  C | D
    // Sum = A + B + C + D => D = SUM  - (A+B)(right up) - (A+C) (left down) + A
    int sumRegion(int row1, int col1, int row2, int col2) {
        ++row1, ++col1, ++row2, ++col2; // convert to new coordinate system (for matrix)
        int sum = Matrix_[row2][col2];

        int rightUp = Matrix_[row1 - 1][col2];  
        int leftDown = Matrix_[row2][col1-1];
        int leftUp = Matrix_[row1-1][col1-1];

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