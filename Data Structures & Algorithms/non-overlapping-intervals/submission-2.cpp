class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals);
        int result = 0;
        int right = INT_MIN;
        for (const auto& interval: intervals) {
            if (right <= interval[0]) {
                right = interval[1];
            } else { // overlap
                result++;
                right = min(right, interval[1]);
            }
        }
        return result;
    }
    // int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    //     unordered_map<int, int> cache;
    //     ranges::sort(intervals);
    //     int maxCount = dfs(intervals[0][0], intervals, cache);
    //     return intervals.size() - maxCount;
    // }

    // int dfs(
    //     int start,
    //     const vector<vector<int>>& intervals,
    //     unordered_map<int, int>& cache) 
    // {
    //     if (cache.contains(start)) {
    //         return cache[start];
    //     }
    //     int count = 0;
    //     for (const auto& interval: intervals) {
    //         if (interval[0] < start) {
    //             continue;
    //         }
    //         count = max(count, 1 + dfs(interval[1] , intervals, cache));
    //     }

    //     cache[start] = count;
    //     return count;
    // }
};
