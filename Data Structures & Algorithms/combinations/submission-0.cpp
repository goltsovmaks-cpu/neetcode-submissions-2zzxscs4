class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(1, n, k, path, result);
        return result;
    }

    void dfs(int startIndex, int maxIndex, int maxLen, vector<int>& path, vector<vector<int>>& out)
    {
        if (path.size() == maxLen) {
            out.push_back(path);
            return;
        }


        for (int i = startIndex; i <= maxIndex; i++) {
            // take
            path.push_back(i);
            dfs(i+1, maxIndex, maxLen, path, out);
            path.pop_back();
        }
    }
};