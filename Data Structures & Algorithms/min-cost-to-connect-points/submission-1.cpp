class Solution {
public:
    // classic prims
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> graph(points.size(), vector<int>(points.size(), INT_MAX));
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                int distance = 
                    abs(points[i][0] - points[j][0]) + 
                    abs(points[i][1] - points[j][1]);
                graph[i][j] = distance;
                graph[j][i] = distance;
            }
        }

        vector<bool> visited(points.size(), false);
        using T = pair<int, int>; // weight, node;
        priority_queue<T, vector<T>, std::greater<T>> queue;
        queue.push({0, 0});

        int sum = 0;

        while (!queue.empty()) {
            auto [w, nodeIdx] = queue.top();
            queue.pop();
            if (visited[nodeIdx]) {
                continue;
            }

            sum+=w;
            visited[nodeIdx] = true;;

            const auto& neighbors = graph[nodeIdx];
            for (int i = 0; i < neighbors.size(); i++) {
                if (visited[i]) {
                    continue;
                }
                queue.push({neighbors[i], i});
            }
        }
        return sum;
    }

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
