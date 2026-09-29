class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n, 0);
        ranges::iota(parents, 0);

        int count = n;

        for (auto& edge: edges) {
            int a = edge[0];
            int b = edge[1];
            int parentA = find(parents, a);
            int parentB = find(parents, b);

            if (parentA == parentB) {
                continue;
            }
            // union
            count--;
            parents[parentA] = parentB;
        }
        return count;
    }
    int find(vector<int>& parents, int pos) {
        while (pos != parents[pos]) {
            // set grandparent instead of parent
            parents[pos] = parents[parents[pos]];
            pos = parents[pos];
        }
        return pos;
    }


    // {
        // unordered_map<int, unordered_set<int>> graphs;
        // for (auto& edge: edges) {
        //     int a = edge[0];
        //     int b = edge[1];
        //     graphs[a].insert(b);
        //     graphs[b].insert(a);
        // }
        // int count = 0;
        // vector<bool> visitedNodes(n, false);
        // for (int i = 0; i < n; i++) {
        //     if (!visitedNodes[i]) {
        //        count++;
        //        dfs(graphs, i, visitedNodes); 
        //     }
        // }
        // return count;
    // }

    // void dfs(
    //     unordered_map<int, unordered_set<int>>& graphs,
    //     int start, 
    //     vector<bool>& visitedNode)
    // {
    //     if (visitedNode[start]) {
    //         return;
    //     }
    //     visitedNode[start] = true;
    //     for (int adj :graphs[start]) {
    //         dfs(graphs, adj, visitedNode);
    //     }
    // }
};
