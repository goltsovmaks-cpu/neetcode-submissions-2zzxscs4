/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 1;
        int r = mountainArr.length() - 2;

        int maxIdx = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int midNum = mountainArr.get(m);
            int nextNum = mountainArr.get(m+1);
            int prevNum = mountainArr.get(m-1);

            if (midNum > nextNum && midNum > prevNum) {
                maxIdx = m;
                break;
            }

            if (midNum < nextNum) {
                l = m + 1;
            } else { 
                r = m - 1;
            }
        }

        // try left

        l = 0;
        r = maxIdx;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int midNum = mountainArr.get(m);

            if (target == midNum) {
                return m;
            }
            if (target < midNum) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        l = maxIdx;
        r = mountainArr.length() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int midNum = mountainArr.get(m);
            if (target == midNum) {
                return m;
            }
            if (target < midNum) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }
};