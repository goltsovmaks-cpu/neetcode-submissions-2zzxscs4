class Solution {
public:
    struct Dsu {
        Dsu(int n)
            : Parents(n)
            , Ranks(n, 1)
        {
            ranges::iota(Parents, 0);
        }

        int Find(int curr)
        {
            while (Parents[curr] != curr) {
                Parents[curr] = Parents[Parents[curr]];
                curr = Parents[curr];
            }
            return curr;
        }

        bool Union(int a, int b) 
        {
            int parentA = Find(a);
            int parentB = Find(b);
            if (parentA == parentB) {
                return false;
            }

            if (Ranks[parentA] > Ranks[parentB]) {
                Ranks[parentA] += Ranks[parentB];
                Parents[parentB] = parentA;
            } else {
                Ranks[parentB] += Ranks[parentA];
                Parents[parentA] = parentB;
            }
            return true;
        }

        vector<int> Parents;
        vector<int> Ranks;
    };

    // classic kruskal's
    int minCostConnectPoints(vector<vector<int>>& points) {
        using T = pair<int, pair<int,int>>; // w, a,b
        priority_queue<T, vector<T>, greater<T>> queue;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                int distance = 
                    abs(points[i][0] - points[j][0]) + 
                    abs(points[i][1] - points[j][1]);
                queue.push({distance, {i, j}});
            }
        }

        Dsu dsu(points.size());
        int result = 0;

        while (!queue.empty()) {
            auto [w, link] = queue.top();
            queue.pop();
            auto [a, b] = link;

            if (dsu.Union(a, b)) {
                result += w;
            }
        }
        return result;
    }


    // classic prims
    // int minCostConnectPoints(vector<vector<int>>& points) {
    //     vector<vector<int>> graph(points.size(), vector<int>(points.size(), INT_MAX));
    //     for (int i = 0; i < points.size(); i++) {
    //         for (int j = i+1; j < points.size(); j++) {
    //             int distance = 
    //                 abs(points[i][0] - points[j][0]) + 
    //                 abs(points[i][1] - points[j][1]);
    //             graph[i][j] = distance;
    //             graph[j][i] = distance;
    //         }
    //     }

    //     vector<bool> visited(points.size(), false);
    //     using T = pair<int, int>; // weight, node;
    //     priority_queue<T, vector<T>, std::greater<T>> queue;
    //     queue.push({0, 0});

    //     int sum = 0;

    //     while (!queue.empty()) {
    //         auto [w, nodeIdx] = queue.top();
    //         queue.pop();
    //         if (visited[nodeIdx]) {
    //             continue;
    //         }

    //         sum+=w;
    //         visited[nodeIdx] = true;;

    //         const auto& neighbors = graph[nodeIdx];
    //         for (int i = 0; i < neighbors.size(); i++) {
    //             if (visited[i]) {
    //                 continue;
    //             }
    //             queue.push({neighbors[i], i});
    //         }
    //     }
    //     return sum;
    // }

    // modified prims
    // int minCostConnectPoints(vector<vector<int>>& points) {
    //     vector<pair<int, bool>> weights(points.size(), {INT_MAX, false});
    //     weights[0].first = 0;

    //     int sum = 0;

    //     int pointsLeft = points.size();
    //     while (pointsLeft > 0) {
    //         int minPointIdx = weights.size();;
    //         for (int i = 0; i < weights.size(); i++) {
    //             if (weights[i].second) {
    //                 continue;
    //             }
    //             if (weights.size() == minPointIdx 
    //                 || weights[i] < weights[minPointIdx])
    //             {
    //                 minPointIdx = i;
    //             }
    //         }

    //         sum += weights[minPointIdx].first;
    //         weights[minPointIdx].second = true;

    //         for (int i = 0; i < points.size(); i++) {
    //             if (weights[i].second) {
    //                 continue;
    //             }
    //             int distance = 
    //                 abs(points[i][0] - points[minPointIdx][0]) +
    //                 abs(points[i][1] - points[minPointIdx][1]);
    //             weights[i].first = min(weights[i].first, distance);
    //         }
    //         pointsLeft--;
    //     }

    //     return sum; 
    // }
};
