class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& left, const vector<int>& right) {
            int distanceFirst = pow(left[0], 2) + pow(left[1], 2);
            int distanceSecond = pow(right[0], 2) + pow(right[1], 2);
            return distanceFirst > distanceSecond;
        };
        std::priority_queue queue(cmp, points);
        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            result.push_back(queue.top());
            queue.pop();
        }
        return result;
    }
};
