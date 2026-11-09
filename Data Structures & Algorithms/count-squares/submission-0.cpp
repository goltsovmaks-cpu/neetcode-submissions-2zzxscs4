class CountSquares {
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        Points_[x][y]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int result = 0;
        for (auto [yi, count]: Points_[x]) {
            int distance = abs(y - yi);
            if (0 == distance) {
                continue;
            }

            int squaresCount = count;
            // go left
            int leftX = x - distance;
            result += squaresCount * Points_[leftX][y] * Points_[leftX][yi];

            // go right
            int rightX = x + distance;
            result += squaresCount * Points_[rightX][y] * Points_[rightX][yi];
        }

        return result;
    }

    unordered_map<int, unordered_map<int, int>> Points_; // x->y's->count
};
