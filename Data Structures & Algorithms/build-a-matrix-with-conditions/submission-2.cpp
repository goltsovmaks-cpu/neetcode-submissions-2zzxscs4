class Solution {
public:
    vector<vector<int>> buildMatrix(
        int k, vector<vector<int>>& rowConditions,
        vector<vector<int>>& colConditions)
    {
        vector<vector<int>> result;
        vector<vector<int>> dots(k + 1, {-1, -1});
        if (DoComputeConditions(k, rowConditions, dots, 0) && 
            DoComputeConditions(k, colConditions, dots, 1) )
        {
            result = vector<vector<int>>(k, vector<int>(k, 0));
            for (int i = 1; i <=k; i++) {
                int row = dots[i][0];
                int col = dots[i][1];
                result[row][col] = i;
            }
        }
        return result;
    }

    bool DoComputeConditions(
        int k,
        vector<vector<int>>& conditions,
        vector<vector<int>>& dots,
        int dimention)
    { 
        unordered_map<int, unordered_set<int>> graph;
        for (const auto& cond: conditions) {
            graph[cond[1]].insert(cond[0]);
        }

        vector<int> path;
        unordered_set<int> globalVisited;
        for (int i = 1; i <=k; i++) {
            cerr << i << endl;
            unordered_set<int> localVisited;
            if(!dfs(graph, i, path, globalVisited, localVisited)) {
                return false;
            }
        }
        for (int i = 0; i < path.size(); i++) {
            int num = path[i];
            dots[num][dimention] = i;
        }
        return true;
    }

    bool dfs(
        unordered_map<int, unordered_set<int>>& graph,
        int startNode,
        vector<int>& path,
        unordered_set<int>& globalVisited,
        unordered_set<int>& localVisited)
    {
        cerr << "start check " << startNode << endl;
        // cycle detected
        if (!localVisited.insert(startNode).second) {
            return false;
        }
        // no need to process again
        if (!globalVisited.insert(startNode).second) {
            localVisited.erase(startNode);
            return true;
        }

        for (int adj: graph[startNode]) {
            if (!dfs(graph, adj, path, globalVisited, localVisited)) {
                return false;
            }
        }
        localVisited.erase(startNode);
        path.push_back(startNode);
        return true;
    }

};










