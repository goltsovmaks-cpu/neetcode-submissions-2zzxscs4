class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ranges::sort(nums);
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtracking(nums, used, path, result);
        return result;
    }

    void backtracking(const vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& out) {

        if (path.size() == nums.size()) {
            out.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }

            // hack, if we take prev number - we go deep
            // else -> we made used[i] = false and go breadth, skip dublicates
            if (i !=0 && nums[i] == nums[i-1] && !used[i-1]) {
                continue;
            }

            // take that number
            used[i] = true;
            int num = nums[i];
            path.push_back(num);
            backtracking(nums, used, path, out);
            path.pop_back();
            used[i] = false;

            // // do not take - just skip
            // while (i+1 < nums.size() && num == nums[i+1]) {
            //     i++;
            // }
        }
    }
};