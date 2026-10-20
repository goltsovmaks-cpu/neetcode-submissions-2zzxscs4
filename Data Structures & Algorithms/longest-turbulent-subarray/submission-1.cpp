class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        bool mustBeGreater = false;
        int prev = arr[0];

        int currentLenght = 1;
        int bestLenght = 1;

        for (int i = 1; i < arr.size(); i++) {
            int num = arr[i];
            if (num > prev && mustBeGreater ||
                num < prev && !mustBeGreater) 
            {
                currentLenght++;
                mustBeGreater = !mustBeGreater;
            } else if (num == prev) {
                currentLenght = 1;
            } else {
                currentLenght = 2;
            }

            prev = num;
            bestLenght = max(bestLenght, currentLenght);
        }
        return bestLenght;
    }
};