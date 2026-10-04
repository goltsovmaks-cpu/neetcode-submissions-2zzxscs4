class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto& edge: edges) {
            int a = edge[0];
            int b = edge[1];

            graph[a].insert(b);
            graph[b].insert(a);
        }

        queue<int> leaves;
        for (const auto& [node, neighbors]: graph) {
            if (neighbors.size() == 1) {
                leaves.push(node);
            }
        }

        while (!leaves.empty()) {
            if (graph.size() <= 2) {
                vector<int> result;
                while(!leaves.empty()){
                    result.push_back(leaves.front());
                    leaves.pop();
                }
                return result;
            }
            int lenght = leaves.size();
            for (int i = 0; i < lenght; i++) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : graph[leaf]) {
                    graph[neighbor].erase(leaf);
                    if (graph[neighbor].size() == 1) {
                        leaves.push(neighbor);
                    }
                }
                graph.erase(leaf);
            }

        }
        return {0};
    }
    // struct TEdge {
    //     int Node;
    //     int Depth = 1;
    // };
    // vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    //     unordered_map<int, vector<TEdge>> graph;
    //     for (auto& edge: edges) {
    //         int a = edge[0];
    //         int b = edge[1];

    //         graph[a].push_back(TEdge{
    //             .Node = b});
    //         graph[b].push_back(TEdge{
    //             .Node = a});
    //     }
    //     calculateDirectDepth(graph, -1, 0);

    //     vector<int> depth(n, INT_MAX);
    //     findMinDepth(graph, {-1, 0}, 0, depth);

    //     int minD = *ranges::min_element(depth);
    //     vector<int> result;
    //     for (int i = 0; i < depth.size(); i++) {
    //         if (depth[i] == minD) {
    //             result.push_back(i);
    //         }
    //     }
    //     return result;
    // }

    // int calculateDirectDepth(unordered_map<int, vector<TEdge>>& graph, int prev, int curr) {
    //     int maxDepth = 0;

    //     for (auto& adj: graph[curr]) {
    //         if (adj.Node == prev) {
    //             continue;
    //         }

    //         adj.Depth = calculateDirectDepth(graph, curr, adj.Node);
    //         maxDepth = max(maxDepth, adj.Depth);
    //     }
    //     return 1 + maxDepth;
    // }

    // void findMinDepth(
    //     unordered_map<int, vector<TEdge>>& graph,
    //     pair<int, int> prev, // node, count
    //     int curr,
    //     vector<int>& depth)
    // {
    //     pair<int,int> maxAdj; // depth, node.
    //     for (const auto& adj: graph[curr]) {
    //         if (adj.Node == prev.first) {
    //             continue;
    //         }
    //         if (adj.Depth > maxAdj.first) {
    //             maxAdj.first = adj.Depth;
    //             maxAdj.second = adj.Node;
    //         }
    //     }

    //     depth[curr] = 1 + max(maxAdj.first, prev.second);
    //     if (0 == maxAdj.first) {
    //         return;
    //     }

    //     int maxAdjDeep = prev.second;

    //     for (const auto& adj: graph[curr]) {
    //         if (adj.Node == prev.first || adj.Node == maxAdj.second) {
    //             continue;
    //         }
    //         maxAdjDeep = max(maxAdjDeep, adj.Depth);
    //     }
    //     findMinDepth(graph, {curr, maxAdjDeep+1}, maxAdj.second, depth);
    // }
};



















