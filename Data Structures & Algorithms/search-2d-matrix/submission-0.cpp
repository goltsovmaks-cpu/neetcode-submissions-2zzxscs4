class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() - 1;

        // first, find row.
        int index = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            int firstItem = matrix[mid][0];
            
            if (firstItem < target) {
                index = mid;
                left = mid + 1;
            } else if (firstItem > target) {
                right = mid - 1;
            } else { 
                return true;
            }
        }

        // second - find item in closest row.
        const auto& row = matrix[index];
        left = 0;
        right = row.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int item = row[mid];
            if (item < target) {
                left = mid + 1;
            } else if (item > target) { 
                right = mid - 1;
            } else { 
                return true;
            }
        }
        return false;
    }
};
