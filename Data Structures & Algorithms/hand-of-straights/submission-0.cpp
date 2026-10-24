class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        ranges::sort(hand);
        unordered_map<int, vector<int>> groups;

        for (int num: hand) {
            auto prev = groups.find(num-1);
            int lenght = 1;
            if (groups.end() != prev) { // continue seq
                lenght = prev->second.back();
                lenght++;

                prev->second.pop_back();
                if (prev->second.empty()) {
                    groups.erase(prev);
                }
            }

            if (lenght < groupSize) {
                groups[num].push_back(lenght);
            }
        }

        return groups.empty();
    }
};
