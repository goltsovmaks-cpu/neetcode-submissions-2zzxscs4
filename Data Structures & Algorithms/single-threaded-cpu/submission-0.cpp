class Solution {
private:
    struct TOrigin {
        int EnqueueTime;
        int ProcessingTime;
        int Index;
    };
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        using TOrigin = tuple<int,int,int>; // enqueu, processing, idx
        vector<TOrigin> sorted;
        for (int i = 0; i < tasks.size(); i++) {
            sorted.emplace_back(
                tasks[i][0],
                tasks[i][1],
                i
            );
        }
        vector<int> result;
        ranges::sort(sorted);

        int currentTime = 0;
        int idx = 0;
        using T = pair<int,int>;

        priority_queue<T, vector<T>, std::greater<T>> pq;
        while (idx != sorted.size() || !pq.empty()) {
            while (idx != sorted.size()) {
                auto task = sorted[idx];
                if (currentTime < get<0>(task)) {
                    break;
                }
                pq.push({get<1>(task), get<2>(task)});
                idx++;
            }

            if (pq.empty()) {
                currentTime = get<0>(sorted[idx]);
            } else {
                auto task = pq.top();
                pq.pop();
                currentTime += task.first;
                result.push_back(task.second);
            }
        }
        return result;
    }
};