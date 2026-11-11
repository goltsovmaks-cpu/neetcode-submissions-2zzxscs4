class Solution {
public:
    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     int left = newInterval[0];
    //     int right = newInterval[1];
    //     int start = 0;
    //     int end = start;
    //     for (int i = 0; i < intervals.size(); i++) {
    //         int currLeft = intervals[i][0];
    //         int currRight = intervals[i][1];
    //         if (currRight < left) {
    //             start = i+1;
    //             end = start;
    //         } else if (min(right, currRight) >= max(left, currLeft)) { // overlaps
    //             // just in case
    //             left = min(left, currLeft);
    //             right = max(right, currRight);
    //             end = i + 1;
    //         }
    //     }

    //     intervals.erase(intervals.begin() + start, intervals.begin() + end);
    //     intervals.insert(intervals.begin() + start, {left, right});
    //     return intervals;
    // }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); i++) {
            int leftI = intervals[i][0];
            int rightI = intervals[i][1];
            if (right < leftI) {
                result.push_back({left, right});
                result.insert(result.end(), intervals.begin() + i, intervals.end());
                return result;
            } else if (rightI < left) {
                result.push_back(intervals[i]);
            } else { // collision
                left = min(left, leftI);
                right = max(right, rightI);
            }
        }
        result.push_back({left, right});
        return result;
    }
};
