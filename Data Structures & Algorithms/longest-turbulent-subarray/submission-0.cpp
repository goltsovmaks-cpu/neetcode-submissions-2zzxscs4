class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        bool mustBeGreater = false;
        int prev = arr[0];

        int currentLenght = 1;
        int bestLenght = 1;

        for (int i = 1; i < arr.size(); i++) {
            int num = arr[i];
            if (num > prev) {
                if (mustBeGreater) { //
                    currentLenght++;
                    mustBeGreater = !mustBeGreater;
                } else {
                    currentLenght = 2;
                }
            } else if (num < prev) {
                if (!mustBeGreater) {
                    currentLenght++;
                    mustBeGreater = !mustBeGreater;
                } else {
                    currentLenght = 2;
                }
            } else { // start new cycle
                currentLenght = 1;
            }

            prev = num;
            bestLenght = max(bestLenght, currentLenght);
        }
        return bestLenght;
    }
};