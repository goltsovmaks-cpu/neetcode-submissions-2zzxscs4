#include <utility>
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == k || 0 == k) {
            return;
        }

        // if true - just loop twice - each odd and even (0->0+k, k-> 2k... 1->(k+1), k+1-> 2k+1...)

        int itemsLeft = nums.size();
        int initialIndex = 0;
        int currIdx = initialIndex;
        int itemToMove = nums[initialIndex];
        while (itemsLeft > 0) {
            currIdx = (currIdx + k) % nums.size();
            itemToMove = std::exchange(nums[currIdx], itemToMove);
            if (initialIndex == currIdx) {
                initialIndex = (initialIndex + 1) % nums.size(); // just ++ with ensure.
                currIdx = initialIndex;
                itemToMove = nums[initialIndex];
            }
            itemsLeft--;
        }
    }
};