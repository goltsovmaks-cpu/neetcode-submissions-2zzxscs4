class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        deque<pair<int, int>> posWithSpeed;
        for (size_t i = 0; i < position.size(); i++) {
            posWithSpeed.emplace_back(position[i], speed[i]);
        }
        ranges::sort(posWithSpeed);

        int result = 1;

        pair<int,int> current = posWithSpeed.back();
        posWithSpeed.pop_back();

        while (!posWithSpeed.empty()) {
            // if prev element could reach current - merge them (keep current only).
            float distanceForCurrent = target - current.first;
            float timeForCurrent = distanceForCurrent / current.second;

            pair<int,int> prev = posWithSpeed.back();
            float distanceForPrev = target - prev.first;
            float timeForPrev = distanceForPrev / prev.second;

            if (timeForPrev > timeForCurrent) { // cant merge, create another fleet.
                result++;
                current = prev;
            }
            posWithSpeed.pop_back();
        }

        return result;
    }
};
