class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = std::reduce(nums.begin(), nums.end());
        if (sum % k != 0) {
            return false;
        }
        int targetSum = sum / k;
        vector<int> buckets(k, targetSum);
        std::sort(nums.rbegin(), nums.rend());

        return dfs(nums, 0, buckets);
    }

    bool dfs(const vector<int>& nums, int index, vector<int>& buckets) {
        if (index == nums.size()) {
            bool allZero = std::ranges::all_of(buckets, [](int x){
                return x == 0;
            });
            return allZero;
        }

        int num = nums[index];
        for (int& sum: buckets) {
            if (sum - num < 0) {
                continue;
            }
            sum -= num;
            if (dfs(nums, index + 1, buckets)) {
                return true;
            }
            sum += num;
        }
        return false;
    }
};

















