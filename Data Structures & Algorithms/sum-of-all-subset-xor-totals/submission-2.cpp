class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return subsetXorSum(nums, /*idx*/0, /*currentXor*/0);
    }

    int subsetXorSum(vector<int>& nums, int idx, int currentXor) {
        int res = 0;
        if (nums.size() == idx) {
            return currentXor;
        }
        // 1 chose -> take this num.
        int takeXor = subsetXorSum(nums, idx+1, nums[idx] ^ currentXor);
        int dontTakeXor = subsetXorSum(nums, idx+1, currentXor);
        return takeXor + dontTakeXor;
    }
};