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
            return true;
        }

        int num = nums[index];
        for (int i = 0; i < buckets.size(); i++) {
            int& sum = buckets[i];
            if (buckets[i] - num < 0) {
                continue;
            }

            if (std::find(buckets.begin(), buckets.begin() + i, buckets[i]) != buckets.begin() + i) {
                continue;
            }

            buckets[i] -= num;
            if (dfs(nums, index + 1, buckets)) {
                return true;
            }
            buckets[i] += num;
        }
        return false;
    }
};

















