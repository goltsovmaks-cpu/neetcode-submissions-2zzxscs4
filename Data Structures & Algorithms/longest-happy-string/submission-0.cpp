class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        using T = pair<int, char>;
        priority_queue<T> queue;

        if (a) {queue.push({a, 'a'});}
        if (b) {queue.push({b, 'b'});}
        if (c) {queue.push({c, 'c'});}

        char prev = '0';
        optional<T> cooldown;

        string result;
        while (!queue.empty()) {
            T curr = queue.top();
            queue.pop();

            if (cooldown) {
                queue.push(*cooldown);
                cooldown = nullopt;
            }

            result.push_back(curr.second);
            curr.first--;
            if (curr.first) {
                if (curr.second == prev) {
                    cooldown = curr;
                } else {
                    queue.push(curr);
                }
            }
            prev = curr.second;
        }

        return result;
    }
};