class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        array<int, 3> deltas = {0,0,0};

        for (int i = stoneValue.size() - 1; i >=0; i--) {
            int windowSum = 0;
            int currentMaxDelta = INT_MIN;
            for (int offset = 0; offset < 3; offset++) {
                if (i + offset == stoneValue.size()) {
                    break;
                }
                windowSum += stoneValue[i + offset];

                currentMaxDelta = max(currentMaxDelta, windowSum - deltas[offset]);
            }
            deltas[2] = deltas[1];
            deltas[1] = deltas[0];
            deltas[0] = currentMaxDelta;
        }
        if (0 == deltas[0]) {
            return "Tie";
        } else if (deltas[0] > 0) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};