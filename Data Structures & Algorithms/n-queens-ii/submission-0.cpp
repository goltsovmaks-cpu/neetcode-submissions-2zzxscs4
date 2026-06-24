class Solution {
public:
    int totalNQueens(int n) {
        vector<int> path;
        vector<vector<string>> result;
        dfs(0, n, path, result);
        return result.size();
    }

    void dfs(int runkNum, int n, vector<int>& path, vector<vector<string>>& out) {
        if (runkNum == n) {
            if (path.size() == n) {
                vector<string> position;
                position.reserve(n);
                for (int i = 0; i < n; i++) {
                    string rank(n, '.');
                    rank[path[i]] = 'Q';
                    position.push_back(rank);
                }
                out.push_back(position);
            }
            return;
        }

        // iterate over rank!
        for (int currentFile = 0; currentFile < n; currentFile++) {
            bool skip = false;
            for (int i = 0; i < path.size(); i++) {
                int pathFile = path[i];
                int horizontalDistance = abs(currentFile - pathFile);
                int verticalDistance = abs(runkNum - i);

                if (currentFile == pathFile || horizontalDistance == verticalDistance) {
                    skip = true;
                    break;
                }
            }

            if (skip) {
                continue;
            }

            path.push_back(currentFile);
            dfs(runkNum + 1, n, path, out);
            path.pop_back();
        }
    }
};