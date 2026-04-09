#include <array>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        array<int, 3> counts{};

        for (int num: nums) {
            counts[num]++;
        }

        int curIdx = 0;
        for (int& num: nums) {
            while (0 == counts[curIdx]) {
                curIdx++;
            }

            num = curIdx;
            counts[curIdx]--;
        }
    }
};