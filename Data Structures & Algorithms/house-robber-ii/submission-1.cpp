class Solution {
public:
    int rob(vector<int>& nums) {
        if (1 == nums.size()) {
            return nums[0];
        }
        auto robOnce = [&] (auto startIt, auto endIt) {
            int prev = 0;
            int prevPrev = 0;

            while (startIt != endIt) {
                int current = max(
                    prev,
                    prevPrev + *startIt
                );
                prevPrev = prev;
                prev = current;
                startIt++;
            }
            return prev;
        };
        return max(
            robOnce(nums.begin(), prev(nums.end())),
            robOnce(next(nums.begin()), nums.end())
        );
    }
};
