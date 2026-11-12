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
        for (int i = 0; i + 1 < intervals.size(); i++) {
            bool isCorrect = intervals[i].end <= intervals[i+1].start;
            if (!isCorrect) {
                return false;
            }
        }

        return true;
    }
};
