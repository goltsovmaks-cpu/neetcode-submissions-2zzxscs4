class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int item = nums[mid];
            if (item < target) {
                left = mid + 1;
            } else if (item > target) {
                right = mid;
            } else { 
                return mid;
            }
        }
        return -1;
    }
};
