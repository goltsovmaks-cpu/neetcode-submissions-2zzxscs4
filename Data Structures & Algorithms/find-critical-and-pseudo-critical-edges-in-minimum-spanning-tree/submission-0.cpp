class Solution {
public:
    struct TEdge {
        int Weight;
        int Node;
        int Index;
        bool operator>(const TEdge& other) const {
            return Weight > other.Weight;
        }
    };
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<TEdge>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            const auto& edge = edges[i];
            int a = edge[0];
            int b = edge[1];
            int weight = edge[2];

            graph[a].push_back({
                .Weight = weight,
                .Node = b,
                .Index = i
            });

            graph[b].push_back({
                .Weight = weight,
                .Node = a,
                .Index = i
            });
        }

        vector<vector<int>> result(2); // 0 - critical, 1 - pseudo;
        int bestSum = *findMinimumSpaningTree(graph, edges, nullopt, nullopt);

        for (int i = 0; i < edges.size(); i++) {
            auto forceExclude = findMinimumSpaningTree(graph, edges, nullopt, i);
            if (!forceExclude || *forceExclude > bestSum) {
                result[0].push_back(i);
                continue;
            }
            auto forceInclude = findMinimumSpaningTree(graph, edges, i, nullopt);
            if (forceInclude && *forceInclude == bestSum) {
                result[1].push_back(i);
            }
        }
        return result;
    }

    // return its value
    optional<int> findMinimumSpaningTree(
        const vector<vector<TEdge>>& graph,
        vector<vector<int>>& edges,
        optional<int> includeIndex,
        optional<int> excludeIndex)
    {
        vector<int> result;

        priority_queue<TEdge, vector<TEdge>, greater<TEdge>> queue;
        vector<bool> visited(graph.size());

        auto tryTraverse = [&] (int node) {
            for (const auto& adj: graph[node]) {
                if (visited[adj.Node]) {
                    continue;
                }
                if (excludeIndex && *excludeIndex == adj.Index) {
                    continue;
                }
                queue.push(adj);
            }
        };

        if (includeIndex) {
            result.push_back(*includeIndex);

            int a = edges[*includeIndex][0];
            int b = edges[*includeIndex][1];

            visited[a] = true;
            visited[b] = true;

            tryTraverse(a);
            tryTraverse(b);

        } else {
            visited[0] = true;
            tryTraverse(0);
        }

        while (!queue.empty()) {
            TEdge edge = queue.top();
            queue.pop();

            if (visited[edge.Node]) {
                continue;
            }
            visited[edge.Node] = true;
            result.push_back(edge.Index);

            tryTraverse(edge.Node);
        }
        if (result.size() + 1 != graph.size()) {
            return nullopt;
        }
        int sum = 0;
        for (int index: result) {
            sum+=edges[index][2];
        }
        return sum;
    }
};









