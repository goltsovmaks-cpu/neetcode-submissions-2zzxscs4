class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;
        result.reserve(pow(2,nums.size()));
        vector<int> path;
        dfs(nums, 0, path, result);
        return result;
    }

    void dfs(const vector<int>& nums, int idx, vector<int>& path, vector<vector<int>>& out) {
        if (nums.size() == idx) {
            out.push_back(path);
            return;
        }

        // do not take
        dfs(nums, idx + 1, path, out);

        // take
        path.push_back(nums[idx]);
        dfs(nums, idx + 1, path, out);
        path.pop_back();
    }
};
