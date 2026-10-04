class Solution {
public:
    struct TEdge {
        int Node;
        int Depth = 1;
    };
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<TEdge>> graph;
        for (auto& edge: edges) {
            int a = edge[0];
            int b = edge[1];

            graph[a].push_back(TEdge{
                .Node = b});
            graph[b].push_back(TEdge{
                .Node = a});
        }
        calculateDirectDepth(graph, -1, 0);

        vector<int> depth(n, INT_MAX);
        findMinDepth(graph, {-1, 0}, 0, depth);

        int minD = *ranges::min_element(depth);
        vector<int> result;
        for (int i = 0; i < depth.size(); i++) {
            if (depth[i] == minD) {
                result.push_back(i);
            }
        }
        return result;
    }

    int calculateDirectDepth(unordered_map<int, vector<TEdge>>& graph, int prev, int curr) {
        int maxDepth = 0;

        for (auto& adj: graph[curr]) {
            if (adj.Node == prev) {
                continue;
            }

            adj.Depth = calculateDirectDepth(graph, curr, adj.Node);
            maxDepth = max(maxDepth, adj.Depth);
        }
        return 1 + maxDepth;
    }

    void findMinDepth(
        unordered_map<int, vector<TEdge>>& graph,
        pair<int, int> prev, // node, count
        int curr,
        vector<int>& depth)
    {
        pair<int,int> maxAdj; // depth, node.
        for (const auto& adj: graph[curr]) {
            if (adj.Node == prev.first) {
                continue;
            }
            if (adj.Depth > maxAdj.first) {
                maxAdj.first = adj.Depth;
                maxAdj.second = adj.Node;
            }
        }

        depth[curr] = 1 + max(maxAdj.first, prev.second);
        cerr << curr << depth[curr] << endl;
        if (0 == maxAdj.first) {
            return;
        }

        int maxAdjDeep = prev.second;

        for (const auto& adj: graph[curr]) {
            if (adj.Node == prev.first || adj.Node == maxAdj.second) {
                continue;
            }
            maxAdjDeep = max(maxAdjDeep, adj.Depth);
        }
        findMinDepth(graph, {curr, maxAdjDeep+1}, maxAdj.second, depth);
    }
};



















