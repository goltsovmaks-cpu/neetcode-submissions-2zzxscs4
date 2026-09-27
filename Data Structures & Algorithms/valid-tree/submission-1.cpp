class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto& edge: edges) {
            int a = edge[0];
            int b = edge[1];
            graph[a].insert(b);
            graph[b].insert(a);
        }
        unordered_set<int> visited;
        bool hasCycles =  dfs(graph, 0, -1, visited);
        return hasCycles && visited.size() == n;
    }

    bool dfs(
        unordered_map<int, unordered_set<int>>& graph,
        int node, int prevNode,
        unordered_set<int>& visited)
    {
        if (visited.contains(node)) {
            return false;
        }
        visited.insert(node);
        for (auto& adjancedNode: graph[node]) {
            if (adjancedNode == prevNode) {
                continue;
            }
            if (!dfs(graph, adjancedNode, node, visited)) {
                return false;
            }
        }
        graph[node].clear();
        return true;
    }


    // bool validTree(int n, vector<vector<int>>& edges) {
    //     unordered_map<int, unordered_set<int>> graph;

    //     for (auto& edge: edges) {
    //         int a = edge[0];
    //         int b = edge[1];
    //         graph[a].insert(b);
    //         graph[b].insert(a);
    //     }

    //     unordered_set<int> oneLink;
    //     // keep only 1 node with 1 link (now 2)
    //     for (const auto& [node, links]: graph) {
    //         if (1 == links.size() && !oneLink.contains(*links.begin())) {
    //             oneLink.insert(node);
    //         }
    //     }

    //     int countNode = 0;

    //     while (!oneLink.empty()) {
    //         int nodeToRemove = *oneLink.begin();
    //         oneLink.erase(nodeToRemove);
    //         countNode++;

    //         // where is exactly one link for this node (front)
    //         int connectedNode = *graph[nodeToRemove].begin();
    //         graph.erase(nodeToRemove);

    //         auto& connectedNodeLinks = graph[connectedNode];
    //         connectedNodeLinks.erase(nodeToRemove);
    //         if (
    //             1 == connectedNodeLinks.size() && 
    //             !oneLink.contains(*connectedNodeLinks.begin()))
    //         {
    //             oneLink.insert(connectedNode);
    //         }
    //     }
    //     // now graph has only roots
    //     if (graph.size() > 1) {
    //         return false;
    //     }

    //     // there is two outcomes: 1 node in graph or zero
    //     // if zero that means graph was empty and n == 1; 
    //     return countNode + 1 == n;
    // }
};










