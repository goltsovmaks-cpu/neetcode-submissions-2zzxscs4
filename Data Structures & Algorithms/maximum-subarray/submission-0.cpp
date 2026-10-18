class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int bestSum = *ranges::max_element(nums);

        for (int num: nums) {
            currSum += num;
            if (currSum < 0) {
                currSum = 0;
            } else {
                bestSum = max(currSum, bestSum);
            }
        }

        return bestSum;
    }
};
