class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        // from - to/visited
        unordered_map<string, vector<pair<string, bool>>> graph;
        ranges::sort(tickets);
        for (const auto& ticket: tickets) {
            graph[ticket[0]].emplace_back(ticket[1], false);
        }

        int ticketsLeft = tickets.size();
        vector<string> path;
        string start = "JFK";
        dfs(graph, ticketsLeft, start, path);
        ranges::reverse(path);
        return path;
    }

    void dfs(
        unordered_map<string, vector<pair<string, bool>>>& graph,
        int& ticketsLeft,
        const string& node,
        vector<string>& path)
    {
        for (auto& adj: graph[node]) {
            if (adj.second) {
                continue;
            }
            adj.second = true;
            ticketsLeft--;
            dfs(graph, ticketsLeft, adj.first, path);
        }
        path.push_back(node);
    }
};











