class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int posToInsert = 0;
        int viewPos = 1;

        while (viewPos < nums.size()) {
            if (nums[posToInsert] != nums[viewPos]) {
                posToInsert++;
                nums[posToInsert] = nums[viewPos];
            }
            viewPos++;
        }
        return posToInsert + 1;
    }
};