class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> count;
        for (char task: tasks) {
            count[task]++;
        }
        using TTask = pair<char, int>;
        auto cmp = [](const TTask& left, const TTask& right) {
            return left.second < right.second;
        };
        priority_queue<TTask, vector<TTask>, decltype(cmp)> pool(cmp);
        for (const auto& [task, count]: count) {
            pool.push({task, count});
        }
        queue<pair<TTask, int>> inProgress; // task, ts;

        int ts = 0;
        int cooldown = n;

        while (!pool.empty() || !inProgress.empty()) {
            // coldown ended
            if (!inProgress.empty() && inProgress.front().second + cooldown < ts) {
                auto lastTask = inProgress.front().first;
                inProgress.pop();
                pool.push(lastTask);
            }

            if (!pool.empty()) {
                auto task = pool.top();
                pool.pop();
                task.second--;
                if (0 != task.second) {
                    inProgress.push({task, ts});
                }
            }
            ts++;
        }
        return ts;
    }
};
