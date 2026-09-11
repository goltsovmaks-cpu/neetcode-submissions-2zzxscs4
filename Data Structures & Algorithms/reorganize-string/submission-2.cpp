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

        T prev = {0, '1'};
        string result;

        while (!queue.empty() || prev.first) {

            if (queue.empty()) {
                return "";
            }

            T curr = queue.top();
            queue.pop();
            result.push_back(curr.second);
            curr.first--;

            if (prev.first) {
                queue.push(prev);
            }
            prev = curr;
        }

        return result;
    }
};