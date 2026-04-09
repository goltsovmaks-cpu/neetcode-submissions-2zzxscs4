class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // The key idea - we always have major element
        // that means - we could remove "opposite pairs"
        // (A-B A-B) A 
        int count = 1;
        int currentMajor = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (currentMajor == nums[i]) {
                count++;
            } else {
                if (count > 0) {
                    count--;
                } else {
                    currentMajor = nums[i];
                    count = 1;
                }
            }
        }
        return currentMajor;
    }
};