class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        unordered_map<int, unordered_set<int>> graph; // course -> prerequisites;
        for (auto& pr: prerequisites) {
            int prerequsite = pr[0];
            int course = pr[1];
            graph[course].insert(prerequsite);
        }

        vector<bool> result;
        result.reserve(queries.size());

        // add visited.

        for (auto& query: queries) {
            const int start = query[1];
            const int target = query[0];

            queue<int> queue;
            queue.push(start);
            unordered_set<int> visited;
            visited.insert(start);

            bool found = false;
            while (!queue.empty()) {
                int node = queue.front();
                queue.pop();
                if (target == node) {
                    found = true;
                    break;
                }
                for (int prerequsite: graph[node]) {
                    if (!visited.contains(prerequsite)) {
                        queue.push(prerequsite);
                        visited.insert(prerequsite);
                    }
                }
            }
            result.push_back(found);
        }

        return result;
    }
};






