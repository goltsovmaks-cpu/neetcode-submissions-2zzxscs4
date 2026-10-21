class Solution {
public:
    int jump(vector<int>& nums) {
        int prevSteps = 1;
        int currSteps = 1;

        int jumps = 0;

        for (int num: nums) {
            currSteps--;
            prevSteps--;
            // we cant reach this point
            //need to choose jump (somewhere before)
            if (-1 == currSteps) { 
                currSteps = prevSteps;
                prevSteps = 0;
                jumps++;
            }
            prevSteps = max(prevSteps, num);
        }

        return jumps;
    }
};
