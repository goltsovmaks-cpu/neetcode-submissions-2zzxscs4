class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        ranges::sort(meetings);
        vector<pair<int,int>> rooms(n, {0,0}); // endTime, counter

        for (const auto& meeting: meetings) {
            int startTime = meeting[0];
            int endTime = meeting[1];

            int minTimeRoom = 0;
            bool found = false;

            for (int i = 0; i < rooms.size(); i++) {
                auto& room = rooms[i];
                if (room.first <= startTime) {
                    found = true;
                    room.first = endTime;
                    room.second++;
                    break;
                }
                if (room.first < rooms[minTimeRoom].first) {
                    minTimeRoom = i;
                }
            }

            if (!found) { // have to wait
                int delta = rooms[minTimeRoom].first - startTime;
                rooms[minTimeRoom].first = endTime + delta;
                rooms[minTimeRoom].second++;
            }
        }

        int maxIdx = 0;
        for (int i = 0; i < rooms.size(); i++) {
            if (rooms[i].second > rooms[maxIdx].second) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }
};