class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> tempAndIndex;
        for (size_t i = 0; i < temperatures.size(); i++) {
            int currentTemperature = temperatures[i];
            while(!tempAndIndex.empty() && currentTemperature > tempAndIndex.top().first) {
                int index = tempAndIndex.top().second;
                temperatures[index] = i - index;
                tempAndIndex.pop();
            }
            tempAndIndex.emplace(currentTemperature, i);
        }

        while (!tempAndIndex.empty()) {
            int index = tempAndIndex.top().second;
            temperatures[index] = 0;
            tempAndIndex.pop();
        }

        return temperatures;
    }
};
