class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        vector<int> path;
        dfs(nums, 0, path, target, result);
        return result;
    }

    void dfs(const vector<int>& nums, int startIdx, vector<int>& path, int target, vector<vector<int>>& result) {
        if (target < 0) {
            return;
        }
        if (0 == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIdx; i < nums.size(); i++) {
            // choose crnt
            path.push_back(nums[i]);
            dfs(nums, i, path, target - nums[i], result);
            path.pop_back();
        }
    }
};
