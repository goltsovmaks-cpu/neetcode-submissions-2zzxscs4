class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        int start = 0;
        int end = start;
        for (int i = 0; i < intervals.size(); i++) {
            int currLeft = intervals[i][0];
            int currRight = intervals[i][1];
            if (currRight < left) {
                start = i+1;
                end = start;
            } else if (min(right, currRight) >= max(left, currLeft)) { // overlaps
                // just in case
                left = min(left, currLeft);
                right = max(right, currRight);
                end = i + 1;
            }
        }

        intervals.erase(intervals.begin() + start, intervals.begin() + end);
        intervals.insert(intervals.begin() + start, {left, right});
        return intervals;
    }
};
