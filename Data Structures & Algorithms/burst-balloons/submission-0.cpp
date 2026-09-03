class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        return dfs(nums, 0, nums.size(), dp);
    };

    int dfs(
        const vector<int>& nums,
        int l,
        int r,
        vector<vector<int>>& dp)
    {
        if (l == r) {
            return 0;
        }

        if (dp[l][r]) {
            return dp[l][r];
        }

        int leftItem = 0 == l ? 1 : nums[l-1]; 
        int rightItem = nums.size() == r ? 1 : nums[r]; 

        int res = 0;
        for (int i = l; i < r; i++) {
            // ith - is the last item to erase.
            int curr = leftItem * nums[i] * rightItem +
                dfs(nums, l, i, dp) +
                dfs(nums, i+1, r, dp);
            res = max(res, curr);
        }

        dp[l][r] = res;
        return res;
    }
};
