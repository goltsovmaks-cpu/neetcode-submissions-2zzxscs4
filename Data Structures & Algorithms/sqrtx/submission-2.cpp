class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;

        int BOUND = 46340;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            cerr << mid << endl;

            if (mid > BOUND) { // to big for 2^32.
                right = mid - 1;
                continue;
            }

            int pow2 = mid * mid;
            int distance = x - pow2;
            int deltaBetweenNexNum = mid + (mid+1); // (mid+1) ^ 2;
            if (0 <= distance && distance < deltaBetweenNexNum) {
                return mid; 
            } else if (distance < 0)  { // to big
                right = mid - 1;
            } else { // to smal 
                left = mid + 1;
            }
        }
        return left;
    }
};