class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int leftMin = 1;
        int rightMax = *ranges::max_element(piles);

        int bestSpeed = -1;
        while (leftMin <= rightMax) {
            int speed = leftMin + (rightMax - leftMin) / 2;
            int crntH = 0;
            for (int pile: piles) {
                crntH += (pile + speed - 1) / speed; 
            }

            if (crntH > h) { // too slow
                leftMin = speed + 1;
            } else { // to fast, but maybe ok
                bestSpeed = speed;
                rightMax = speed - 1;
            }
        }
        return bestSpeed;;
    }
};
