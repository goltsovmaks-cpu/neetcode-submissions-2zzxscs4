class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }
        unordered_map<int, int> count;
        int result = 0;
        for (int sum: prefix) {
            if (sum == k) {
                result++;
            }
            result += count[sum - k];
            count[sum]++;
        }
        return result;
    }
};