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
    bool canAttendMeetings(vector<Interval>& intervals) {
        ranges::sort(intervals, [] (const Interval& lhs, const Interval rhs) {
            return lhs.start < rhs.start;
        });
        for (int i = 1; i < intervals.size(); i++) {
            bool isCorrect = intervals[i-1].end <= intervals[i].start;
            if (!isCorrect) {
                return false;
            }
        }

        return true;
    }
};
