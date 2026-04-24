class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int bestLenght = nums.size() + 1;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                bestLenght = min(bestLenght, i - l + 1);
                sum -= nums[l];
                l++;
            }
        }

        if (nums.size() + 1 == bestLenght) {
            return 0;
        }
        return bestLenght;
    }
};