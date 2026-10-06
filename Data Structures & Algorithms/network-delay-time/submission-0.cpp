class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using TLink = pair<int, int>; // node, time
        unordered_map<int, vector<pair<int, int>>> network;
        for (auto& time: times) {
            network[time[0]].push_back({time[1], time[2]});
        }

        unordered_map<int, int> visited(n); // node / time
        using TItem = pair<int, int>; // accumulatedTime, node
        priority_queue<TItem, vector<TItem>, greater<TItem>> queue;
        queue.push({0, k});

        while (!queue.empty()) {
            auto [time, node] = queue.top();
            queue.pop();
            if (!visited.try_emplace(node, time).second) {
                continue;
            }

            for (auto [node, addTime]: network[node]) {
                if (!visited.contains(node)) {
                    queue.push({time+addTime, node});
                }
            }
        }

        if (visited.size() != n) {
            return -1;
        }
        auto it = ranges::max_element(visited, 
            [] (const auto& lhs, const auto& rhs) {
                return lhs.second < rhs.second;
            }
        );

        return it->second;
    }
};
