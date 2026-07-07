class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        int prevPrev = 0;

        for (int money: nums) {
            int current = max(
                money + prevPrev,
                prev
            );
            prevPrev = prev;
            prev = current;
        }
        return prev;
    }
};
