class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = std::reduce(matchsticks.begin(), matchsticks.end());

        if (sum % 4 != 0) {
            return false;
        }
        int targetSum = sum / 4; 

        vector<bool> used(matchsticks.size(), false);
        int sidesLeft = 4;
        return dfs(matchsticks, 0, 0, targetSum, sidesLeft, used);
    }

    bool dfs(
        const vector<int>& nums,
        int startIndex,
        int currentSum,
        int targetSum,
        int sidesLeft,
        vector<bool>& used)
    {
        if (currentSum == targetSum) {
            currentSum = 0;
            startIndex = 0;
            sidesLeft--;
            if (0 == sidesLeft) {
                return true;
            }
        }

        int sumToPass = 0;
        int indexToPass = 0;

        for (int i = startIndex; i < nums.size(); i++) {
            if (used[i] || nums[i] + currentSum > targetSum) {
                continue;
            }
            used[i] = true;
            currentSum += nums[i];

            if (dfs(nums, i+1, currentSum, targetSum, sidesLeft, used)) {
                return true;
            }
            currentSum -= nums[i];
            used[i] = false;
        }
        return false;
    }
};










