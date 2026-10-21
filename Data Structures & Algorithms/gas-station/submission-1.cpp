class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int prevCost = 0;

        int start = 0;
        int lenght = 0;
        int i = 0;

        while(lenght < gas.size()) {
            tank -= prevCost;

            // cannot reach this station, try to start from this one
            if (tank < 0) { 
                if (start > i) { // that means we did cyrcle
                    return -1;
                }
                start = i;
                tank = 0;
                lenght = 0;
            }

            tank = tank + gas[i];
            lenght++;
            prevCost = cost[i];

            i = (i + 1) % gas.size();
        }
        return tank - prevCost >= 0 ? start : -1;
    }
};



























    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int currTank = 0;
    //     int l = 0;
    //     int r = 0;

    //     int width = 0;

    //     while (width < gas.size()) {
    //         currTank += gas[r] - cost[r];
    //         r = (r + 1) % gas.size();
    //         width++;

    //         while (currTank < 0) {
    //             currTank -= (gas[l] - cost[l]);
    //             l++;
    //             width--;

    //             if (gas.size() == l) { // made a loop
    //                 return -1;
    //             }
    //         }
    //     }
    //     return l;
    // }
// };
