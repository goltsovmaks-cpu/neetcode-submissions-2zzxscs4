class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
        
        // int sum = nums.size() * (nums.size() + 1) / 2;
        // for (int num: nums) {
        //     sum-=num;
        // }
        // return sum;


        // for (int i = 0; i < nums.size(); i++) {
        //     while (nums[i] != i && nums[i] < nums.size()) {
        //         swap(nums[i], nums[nums[i]]);
        //     }
        // }

        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] != i) {
        //         return i;
        //     }
        // }
        // return nums.size();
    }
};
