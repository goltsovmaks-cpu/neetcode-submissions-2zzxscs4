class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graphs;
        for (auto& edge: edges) {
            int a = edge[0];
            int b = edge[1];
            graphs[a].insert(b);
            graphs[b].insert(a);
        }
        int count = 0;
        vector<bool> visitedNodes(n, false);
        for (int i = 0; i < n; i++) {
            if (!visitedNodes[i]) {
               count++;
               dfs(graphs, i, visitedNodes); 
            }
        }
        return count;
    }

    void dfs(
        unordered_map<int, unordered_set<int>>& graphs,
        int start, 
        vector<bool>& visitedNode)
    {
        if (visitedNode[start]) {
            return;
        }
        visitedNode[start] = true;
        for (int adj :graphs[start]) {
            dfs(graphs, adj, visitedNode);
        }
    }
};
