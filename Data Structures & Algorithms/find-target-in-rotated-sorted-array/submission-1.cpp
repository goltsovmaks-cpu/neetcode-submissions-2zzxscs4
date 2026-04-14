class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midNum = nums[mid];
            int leftNum = nums[left];
            int rightNum = nums[right];

            if (target == midNum) {
                return mid;
            } else if (target == leftNum) {
                return left;
            } else if (target == rightNum) {
                return right;
            }

            bool leftSorted = leftNum < midNum;

            bool goLeft = leftSorted && (leftNum < target && target < midNum);
            goLeft = goLeft || (
                !leftSorted && (target > leftNum || target < midNum)
            );
            
            if (goLeft) {
                right = mid - 1;
            } else { 
                left = mid + 1;
            }
        }
        return -1;
    }
};
