class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // find cycle
        int slow = 0;
        int fast = 0;
        do {
            // 2 steps for fast
            fast = nums[fast];
            fast = nums[fast];

            slow = nums[slow];
        } while (slow != fast);

        int head = 0;
        while (head != slow) {
            head = nums[head];
            slow = nums[slow];
        }
        return head;
    }
};
