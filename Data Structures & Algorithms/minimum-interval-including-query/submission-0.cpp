class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        ranges::sort(intervals);

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        ranges::sort(sortedQueries);

        using TItem = pair<int, int>; // lenght, start
        priority_queue<TItem, vector<TItem>, greater<TItem>> pq;
        vector<int> result(queries.size(), -1);
        int curr = 0;
        for (auto [num, i]: sortedQueries) {
            while(curr < intervals.size() && intervals[curr][0] <= num) {
                int start = intervals[curr][0];
                int end = intervals[curr][1];
                pq.push({end - start + 1, start});
                curr++;
            }

            while (!pq.empty()) {
                auto [lenght, start] = pq.top();
                if (start <= num && num <= start + lenght - 1) {
                    break;
                }
                pq.pop();
            }

            result[i] = pq.empty() ? -1 : pq.top().first;
        }

        return result;
    }
};
