class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        dfs(nums, 0, nums.size());
        return nums;
    }

    void dfs(vector<int>& nums, int begin, int end)
    {
        if (end - begin <= 1) {
            return;
        }

        int base = nums[end - 1];
        int left = begin;
        int right = end - 1;

        while (left < right) {
            if (nums[left] <= base) {
                left++;
            } else if (base < nums[right] ) {
                right--;
            } else {
                swap(nums[left], nums[right]);
            }
        }

        dfs(nums, begin, left);
        dfs(nums, left, end);
    }
    // vector<int> sortArray(vector<int>& nums) {
    //     dfs(nums, 0, nums.size());
    //     return nums;
    // }

    // void dfs(vector<int>& nums, int begin, int end)
    // {
    //     if (end - begin <= 1) {
    //         return;
    //     }

    //     int firstGreater = begin;
    //     for (int i = begin; i < end - 1; i++) {
    //         if (nums[i] <= nums[end-1]) {
    //             swap(nums[i], nums[firstGreater]);
    //             firstGreater++;
    //         }
    //     }
    //     swap(nums[end-1], nums[firstGreater]);
        
    //     dfs(nums, begin, firstGreater);
    //     dfs(nums, firstGreater + 1, end);
    // }

};