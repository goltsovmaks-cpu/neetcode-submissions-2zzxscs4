class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        ranges::sort(nums);
        int k = 4;
        vector<vector<int>> result;
        vector<int> state;
        dfs(nums, 0, target, k, result, state);
        return result;
    }

    void dfs(
        vector<int>& nums,
        int start,
        long long target,
        int k,
        vector<vector<int>>& result,
        vector<int>& state)
    {
        if (k == 2) {
            find2Sum(nums, start, target, state, result);
        } else {
            k--;
            for (int i = start; i < ssize(nums) - k; i++) {
                if (i != start && nums[i] == nums[i-1]) {
                    continue;
                }
                state.push_back(nums[i]);
                dfs(nums, i + 1, target - nums[i], k, result, state);
                state.pop_back();
            }
        }
    }

    void find2Sum(
        vector<int>& nums,
        int start,
        long long target,
        vector<int>& state,
        vector<vector<int>>& result)
    {
        int left = start;
        int right = nums.size() - 1;
        while (left < right) {
            long long sum = nums[left] + nums[right];
            if (sum == target) {
                state.push_back(nums[left]);
                state.push_back(nums[right]);
                result.push_back(state);
                state.pop_back();
                state.pop_back();
                left++;
                right--;

                while (left < right && nums[left-1] == nums[left]) {
                    left++;
                }
                while (left < right && nums[right+1] == nums[right]) {
                    right--;
                }

            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
};