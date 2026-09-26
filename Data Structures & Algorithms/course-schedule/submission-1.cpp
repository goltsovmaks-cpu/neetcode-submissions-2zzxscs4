class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> dependencies;
        for (auto& p: prerequisites) {
            dependencies[p[0]].push_back(p[1]);
        }
        vector<bool> passed(numCourses, false);
        vector<bool> visited(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!isPossibleToPass(i, dependencies, passed, visited)) {
                return false;
            }
        }
        return true;
    }

    bool isPossibleToPass(
        int num,
        unordered_map<int, vector<int>>& dependencies,
        vector<bool>& passed,
        vector<bool>& visited
    ) {

        if (passed[num]) return true;
        if (visited[num]) return false;

        visited[num] = true;
        for (const auto& required: dependencies[num]) {
            if (!isPossibleToPass(required, dependencies, passed, visited)) {
                return false;
            }
        }
        visited[num] = false;

        passed[num] = true;
        return true;
    }
};
