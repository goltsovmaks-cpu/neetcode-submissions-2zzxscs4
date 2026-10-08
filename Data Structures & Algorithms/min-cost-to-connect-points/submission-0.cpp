class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, bool>> weights(points.size(), {INT_MAX, false});
        weights[0].first = 0;

        int sum = 0;

        int pointsLeft = points.size();
        while (pointsLeft > 0) {
            int minPointIdx = weights.size();;
            for (int i = 0; i < weights.size(); i++) {
                if (weights[i].second) {
                    continue;
                }
                if (weights.size() == minPointIdx 
                    || weights[i] < weights[minPointIdx])
                {
                    minPointIdx = i;
                }
            }

            sum += weights[minPointIdx].first;
            weights[minPointIdx].second = true;

            for (int i = 0; i < points.size(); i++) {
                if (weights[i].second) {
                    continue;
                }
                int distance = 
                    abs(points[i][0] - points[minPointIdx][0]) +
                    abs(points[i][1] - points[minPointIdx][1]);
                weights[i].first = min(weights[i].first, distance);
            }
            pointsLeft--;
        }

        return sum;
        
    }
};
