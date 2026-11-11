class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {{}};
        }
        ranges::sort(intervals);
        vector<vector<int>> result;
        result.reserve(intervals.size());
        int left = intervals[0][0];
        int right = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (right < intervals[i][0]) { // new interval - flush 
                result.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            } else {
                right = max(right, intervals[i][1]);
            }
        }

        result.push_back({left, right});
        return result;
    }
};
