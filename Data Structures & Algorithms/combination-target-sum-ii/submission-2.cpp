class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        ranges::sort(candidates);

        dfs(candidates, 0, target, path, result);
        return result;
    }

    void dfs(
        const vector<int>& candidates,
        int index,
        int target,
        vector<int>& path,
        vector<vector<int>>& out)
    {
        if (0 == target ) {
            out.push_back(path);
            return;
        }

        if (candidates.size() == index ||
            target - candidates[index] < 0)
        {
            return;
        }

        // take
        int num = candidates[index];
        path.push_back(num);
        dfs(candidates, index + 1, target-num, path, out);
        path.pop_back();

        // do not take (but skip copies)
        while (index + 1 < candidates.size() and candidates[index] == candidates[index+1]) {
            index++;
        }
        dfs(candidates, index + 1, target, path, out);
    }
};
