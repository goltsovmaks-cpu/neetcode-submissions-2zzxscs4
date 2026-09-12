template <class T>
using TMinQueue = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        using TFinish = pair<int, int>; // finishTime, count
        using TTrip = pair<int, TFinish>; // startTime, tfinish

        TMinQueue<TTrip> startQueue;
        for (auto& trip: trips) {
            startQueue.push({
                trip[1],
                {trip[2], trip[0]}
            });
        }

        TMinQueue<TFinish> finishQueue;
        int capacityLeft = capacity;
        int currKm = 0;

        while (!startQueue.empty()) {
            currKm = startQueue.top().first;
            if (!finishQueue.empty()) {
                currKm = min(currKm, finishQueue.top().first);
            }
            
            while (!finishQueue.empty() && finishQueue.top().first == currKm) { // go away passangers
                capacityLeft += finishQueue.top().second;
                finishQueue.pop();
            }

            while (!startQueue.empty() && startQueue.top().first == currKm) { // add new passangers
                TFinish finish = startQueue.top().second;
                startQueue.pop();

                capacityLeft -= finish.second;
                finishQueue.push(finish);
            }

            if (capacityLeft < 0) {
                return false;
            }
        }
        return true;
        
    }
};