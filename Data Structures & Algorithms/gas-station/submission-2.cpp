class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;

        int start = 0;
        int lenght = 0;
        int i = 0;

        while(lenght < gas.size()) {
            tank = tank + gas[i] - cost[i];

            // cannot out from this station, try to start from next one
            if (tank < 0) { 
                if (start > i) { // that means we did cyrcle
                    return -1;
                }
                start = i+1;
                tank = 0;
                lenght = 0;
            } else {
                lenght++;
            }
            i = (i + 1) % gas.size();
        }
        return start;
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
