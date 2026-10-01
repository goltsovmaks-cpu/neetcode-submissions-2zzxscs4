class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for (auto& edge: edges) {
            n = max(n, edge[0]);
            n = max(n, edge[1]);
        }
        vector<int> parents(n + 1);
        vector<int> ranks(n + 1, 1);
        ranges::iota(parents, 0);

        // find root
        auto find = [&] (int node) {
            while (parents[node] != node) {
                parents[node] = parents[parents[node]];
                node = parents[node];
            }
            return node;
        };

        for (auto& edge: edges) {
            int rootA = find(edge[0]);
            int rootB = find(edge[1]);
            if (rootA == rootB) {
                return edge;
                continue;
            }
            if (ranks[rootA] > ranks[rootB]) {
                ranks[rootA]+= ranks[rootB];
                parents[rootB] = rootA;
            } else {
                ranks[rootB]+= ranks[rootA];
                parents[rootA] = rootB;
            }
        }
        return {};
    }
    // vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    //     unordered_map<int, unordered_set<int>> graph;
    //     for (auto& edge: edges) {
    //         int a = edge[0];
    //         int b = edge[1];
    //         graph[a].insert(b);
    //         graph[b].insert(a);
    //     }
    //     // collect cycle 
    //     vector<int> path;
    //     unordered_set<int> visitedNode;
    //     int cycleNode = dfs(graph, 1, path, visitedNode);
    //     for (int node: path) {
    //         if (cycleNode == node) {
    //             break;
    //         }
    //         visitedNode.erase(node);
    //     }
    //     for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
    //         int a = (*it)[0];
    //         int b = (*it)[1];
    //         if (visitedNode.contains(a) && visitedNode.contains(b)) {
    //             return {a, b};
    //         }
    //     }
    //     return {};
    // }

    // int dfs(
    //     unordered_map<int, unordered_set<int>>& graph,
    //     int start, 
    //     vector<int>& path,
    //     unordered_set<int>& visitedNode
    // ) {
    //     if (visitedNode.contains(start)) {
    //         return start;
    //     }

    //     path.push_back(start);
    //     visitedNode.insert(start);

    //     for (int adj: graph[start]) {
    //         graph[adj].erase(start);
    //         int cycleNode = dfs(graph, adj, path, visitedNode);
    //         if (-1 != cycleNode) {
    //             return cycleNode;
    //         }
    //     }
    //     // this node has no cycles, remove
    //     path.pop_back();
    //     visitedNode.erase(start);
    //     return -1;
    // }
};
