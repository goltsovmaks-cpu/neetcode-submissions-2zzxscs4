class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        ranges::sort(meetings);

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) {freeRooms.push(i);}
        using TItem = pair<int, int>; // unlockTime, room
        priority_queue<TItem, vector<TItem>, greater<TItem>> bookedRooms;
        vector<int> roomCounter(n, 0);

        for (const auto& interval: meetings) {
            int startTime = interval[0];
            int endTime = interval[1];
            while (!bookedRooms.empty() && bookedRooms.top().first <= startTime) {
                freeRooms.push(bookedRooms.top().second);
                bookedRooms.pop();
            }

            if (freeRooms.empty()) { // need to wait, correctEndTime
                auto [unlockTime, roomId] = bookedRooms.top();
                bookedRooms.pop();

                int waitTime = unlockTime - startTime;
                endTime += waitTime;

                freeRooms.push(roomId);
            }

            int roomId = freeRooms.top();
            freeRooms.pop();
            roomCounter[roomId]++;
            bookedRooms.push({endTime, roomId});
        }

        int bestRoom = 0;
        for (int i = 0; i < roomCounter.size(); i++) {
            if (roomCounter[i] > roomCounter[bestRoom]) {
                bestRoom = i;
            }
        }
        return bestRoom;
    }

        // vector<pair<int,int>> rooms(n, {0,0}); // endTime, counter

        // for (const auto& meeting: meetings) {
        //     int startTime = meeting[0];
        //     int endTime = meeting[1];

        //     int minTimeRoom = 0;
        //     bool found = false;

        //     for (int i = 0; i < rooms.size(); i++) {
        //         auto& room = rooms[i];
        //         if (room.first <= startTime) {
        //             found = true;
        //             room.first = endTime;
        //             room.second++;
        //             break;
        //         }
        //         if (room.first < rooms[minTimeRoom].first) {
        //             minTimeRoom = i;
        //         }
        //     }

        //     if (!found) { // have to wait
        //         int delta = rooms[minTimeRoom].first - startTime;
        //         rooms[minTimeRoom].first = endTime + delta;
        //         rooms[minTimeRoom].second++;
        //     }
        // }

        // int maxIdx = 0;
        // for (int i = 0; i < rooms.size(); i++) {
        //     if (rooms[i].second > rooms[maxIdx].second) {
        //         maxIdx = i;
        //     }
        // }
        // return maxIdx;
    // }
};