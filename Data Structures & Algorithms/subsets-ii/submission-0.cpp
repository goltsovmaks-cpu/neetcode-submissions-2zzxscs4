class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ranges::sort(nums);

        vector<vector<int>> result;
        vector<int> path;
        
        backtrack(nums, 0, path, result);
        return result;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& out) {
        if (nums.size() == start) {
            out.push_back(path);
            return;
        }

        // take
        path.push_back(nums[start]);
        backtrack(nums, start + 1, path, out);
        path.pop_back();

        // do not take -- skip
        while (start + 1 < nums.size() && nums[start] == nums[start+1]) {
            start++;
        }
        backtrack(nums, start+1, path, out);
    }
};
