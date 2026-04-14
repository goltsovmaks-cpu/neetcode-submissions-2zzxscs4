class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (target == nums[m]) {
                return true;
            }

            while (nums[l] == nums[m] && l < nums.size()) {
                l++;
            }
            if (l > m) {
                continue;
            }

            if (nums[l] < nums[m]) { // left sorted
                if (nums[l] <= target && target <= nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (target < nums[m] || target > nums[r]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return false;
    }
};