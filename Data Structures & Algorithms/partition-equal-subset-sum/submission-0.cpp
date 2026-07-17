class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> dp;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        dp.reserve(sum);
        dp.insert(0);

        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2; 

        vector<int> temp;
        for (int num: nums) {
            for (int sum: dp) {
                int total = sum + num;
                if (total == target) {
                    return true;
                } else if (total < target) {
                    temp.push_back(total);
                }
            }
            for (int currentEpochSum: temp) {
                dp.insert(currentEpochSum);
            }
            temp.clear();
        }
        return false;
    }
};
