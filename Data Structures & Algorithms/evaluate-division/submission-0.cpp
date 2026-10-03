class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            graph[a].emplace_back(b, values[i]);
            graph[b].emplace_back(a, 1/values[i]);
        }

        vector<double> result;
        unordered_set<string> visited;
        for (auto& query: queries) {
            auto ans = dfs(graph, query[0], query[1], visited);
            result.push_back(ans ? *ans : -1.0);
        }
        return result;
    }

    optional<double> dfs(
        const unordered_map<string, vector<pair<string, double>>>& graph,
        const string& start,
        const string& target,
        unordered_set<string>& visited)
    {
        if (!graph.contains(start) || !graph.contains(target)) {
            return nullopt;
        }
        if (start == target) {
            return 1.0;
        }
        auto [_, emplaced] = visited.insert(start);
        if (!emplaced) {
            return nullopt;
        }
        optional<double> result;
        for (const auto& adj: graph.at(start)) {
            auto ans = dfs(graph, adj.first, target, visited);
            if (ans) {
                result = (*ans) * adj.second;
                break;
            }
        }
        visited.erase(start);
        return result;
    }
};












