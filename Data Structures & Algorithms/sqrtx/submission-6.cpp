class Solution {
public:
    int mySqrt(int x) {
        if (0 == x) {
            return 0;
        }

        int left = 1;
        int right = x;

        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int divRes = x / mid;
            if (divRes < mid) { //too big
                right = mid - 1;
            } else if (divRes > mid) {
                result = mid;
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return result;
    }
};