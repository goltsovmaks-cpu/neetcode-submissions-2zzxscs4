#include <utility>
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //1) convert nums -> index array 
        /*
        [1, 3, 4] ->
        [1, 0, 3]
        */
        // lets fill it cyclic
        for (size_t i = 0; i < nums.size(); i++) {
            int numberToMove = exchange(nums[i], 0);
            int indexForNumber = numberToMove - 1;

            while (
                indexForNumber >= 0 && indexForNumber < nums.size() &&
                numberToMove != nums[indexForNumber]
            )
            {
                numberToMove = exchange(nums[indexForNumber], numberToMove);
                indexForNumber = numberToMove - 1;
            }
        }

        for (size_t i = 0; i < nums.size(); i++) {
            if (0 == nums[i]) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};