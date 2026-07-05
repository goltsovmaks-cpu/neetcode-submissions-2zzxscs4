class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = 0;
        int prevPrev = 0;

        for (int i = 2; i <= cost.size(); i++) {
            int current = min(
                cost[i-1] + prev,
                cost[i-2] + prevPrev
            );
            prevPrev = prev;
            prev = current;
        }
        return prev;
    }
};
