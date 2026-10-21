class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpsLeft = 1;
        for (int num: nums) {
            if (jumpsLeft == 0) {
                return false;
            }
            jumpsLeft--;
            jumpsLeft = max(jumpsLeft, num);
        }

        return true;
    }
};
