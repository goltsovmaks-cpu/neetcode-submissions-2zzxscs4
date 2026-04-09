class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> previous;

        for (int crntA: asteroids) {
            std::optional<int> toPush = crntA;
            while(!previous.empty())
            {
                int prev = previous.top();

                // same direction - add new.
                if (prev < 0 ||
                    prev > 0 && crntA > 0)
                {
                    break;
                }

                if ((-1 * prev) == crntA) { // both collides.
                    previous.pop();
                    toPush = std::nullopt;
                    break;
                }

                if (std::abs(crntA) > std::abs(prev)) {
                    previous.pop();
                } else { // prev destoy current.
                    toPush = std::nullopt;
                    break;
                }
            }
            if (toPush.has_value()) {
                previous.push(*toPush);
            }
        }

        vector<int> result(previous.size(), 0);
        for (int i = previous.size() - 1; i >=0; i--) {
            int value = previous.top();
            previous.pop();
            result[i] = value;
        }
        return result;
    }
};