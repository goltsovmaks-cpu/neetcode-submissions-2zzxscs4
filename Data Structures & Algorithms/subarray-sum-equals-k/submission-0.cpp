class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixToCount;

        int ans = 0;

        int currentSum = 0;

        prefixToCount[0] = 1; //? ??
        for (size_t i = 0; i < nums.size(); i++) {
            currentSum += nums[i];

            int delta = currentSum - k;

            if (auto it = prefixToCount.find(delta); prefixToCount.end() != it) {
                ans += it->second;
            }

            prefixToCount[currentSum]++;
        }

        return ans;
    }
};