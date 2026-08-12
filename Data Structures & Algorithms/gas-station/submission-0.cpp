class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currTank = 0;
        int l = 0;
        int r = 0;

        int width = 0;

        while (width < gas.size()) {
            currTank += gas[r] - cost[r];
            r = (r + 1) % gas.size();
            width++;

            while (currTank < 0) {
                currTank -= (gas[l] - cost[l]);
                l++;
                width--;

                if (gas.size() == l) { // made a loop
                    return -1;
                }
            }
        }
        return l;
    }
};
