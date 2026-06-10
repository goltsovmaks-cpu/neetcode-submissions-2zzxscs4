class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> numCount;
        for (int num: candidates) {
            numCount[num]++;
        }
        vector<pair<int,int>> candidateCount(numCount.begin(), numCount.end());
        ranges::sort(candidateCount);

        vector<vector<int>> result;
        vector<int> path;

        dfs(candidateCount, 0, target, path, result);
        return result;
    }

    void dfs(
        const vector<pair<int, int>>& candidateCount,
        int index,
        int target,
        vector<int>& path,
        vector<vector<int>>& out)
    {
        if (0 == target ) {
            out.push_back(path);
            return;
        }

        if (candidateCount.size() == index ||
            target - candidateCount[index].first < 0)
        {
            return;
        }

        // do not take
        dfs(candidateCount, index + 1, target, path, out);

        // lets take from 0 to n candidates
        int num = candidateCount[index].first;
        int count = candidateCount[index].second;
        for (int i = 0; i < count; i++) {
            path.push_back(num);
            target -= num;
            dfs(candidateCount, index + 1, target, path, out);
        }
        // reverse;
        while (!path.empty() && path.back() == num) {
            path.pop_back();
        }
    }
};
