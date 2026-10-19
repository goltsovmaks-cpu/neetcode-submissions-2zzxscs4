class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        auto [l1, r1] = maxSubbaray(nums);
        int max1 = accumulate(nums.begin() + l1, nums.begin() + r1, 0);

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum +=nums[i];
            nums[i] = -nums[i];
        }
        auto [l2, r2] = maxSubbaray(nums);

        //all negative numbers, just return max
        if (r2-l2 == nums.size()) {
            return max1;
        }

        int min1 = accumulate(nums.begin() + l2, nums.begin() + r2, 0);
        sum+= min1;

        return max(sum, max1);
    }


    pair<int, int> maxSubbaray(vector<int>& nums) {
        int bestSum = nums[0];
        pair<int, int> best{0, 1};

        int curSum = 0;
        int L = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (curSum < 0) {
                curSum = 0;
                L = i;
            }

            curSum += nums[i];
            if (bestSum < curSum) {
                bestSum = curSum;
                best = {L, i+1};
            }
        }
        return best;
    }
};





