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

        unordered_set<int> oneLink;
        // keep only 1 node with 1 link (now 2)
        for (const auto& [node, links]: graph) {
            if (1 == links.size() && !oneLink.contains(*links.begin())) {
                oneLink.insert(node);
            }
        }

        int countNode = 0;

        while (!oneLink.empty()) {
            int nodeToRemove = *oneLink.begin();
            oneLink.erase(nodeToRemove);
            countNode++;

            // where is exactly one link for this node (front)
            cerr << nodeToRemove << graph[nodeToRemove].size();
            int connectedNode = *graph[nodeToRemove].begin();
            graph.erase(nodeToRemove);

            auto& connectedNodeLinks = graph[connectedNode];
            connectedNodeLinks.erase(nodeToRemove);
            if (
                1 == connectedNodeLinks.size() && 
                !oneLink.contains(*connectedNodeLinks.begin()))
            {
                oneLink.insert(connectedNode);
            }
        }
        // now graph has only roots
        if (graph.size() > 1) {
            return false;
        }

        // there is two outcomes: 1 node in graph or zero
        // if zero that means graph was empty and n == 1; 
        return countNode + 1 == n;
    }
};










