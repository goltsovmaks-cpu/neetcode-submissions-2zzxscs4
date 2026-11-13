/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        ranges::sort(intervals, [] (const auto& lhs, const auto& rhs) {
            return lhs.start < rhs.start;
        });
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > queue;
        for (const auto& interval: intervals) {
            if (!queue.empty() && queue.top() <= interval.start) {
                queue.pop();
            }
            queue.push(interval.end);
        }
        return queue.size();
    }
};
