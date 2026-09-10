class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> counter;
        for (char ch: s) {
            counter[ch]++;
        }

        using T = pair<int, char>;
        priority_queue<T, vector<T>, std::less<T>>queue;
        for (auto [ch, count]: counter) {
            queue.push({count, ch});
        }

        if (queue.empty() || queue.top().first > ceil(float(s.size()) / 2.0f)) {
            return "";
        }

        string result; 
        T prev = {0, '1'};
        while (!queue.empty()) {
            T current = queue.top();
            queue.pop();

            current.first--;
            result.push_back(current.second);

            if (prev.first) {
                queue.push(prev);
            }
            prev = current;
        }

        return result;
    }
};