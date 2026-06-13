class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        vector<int> path;
        unordered_set<int> used;
        dfs(nums, used, path, result);
        return result;
    }

    void dfs(
        const vector<int>& nums,
        unordered_set<int>& used,
        vector<int>& path,
        vector<vector<int>>& result)
    {
        if (nums.size() == path.size()) {
            result.push_back(path);
            return;
        }

        for (int num: nums) {
            if (!used.contains(num)) {
                used.insert(num);
                path.push_back(num);
                dfs(nums, used, path, result);
                path.pop_back();
                used.erase(num);
            }
        }
    }

};
