class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0;
        int count10 = 0;

        for (int bill: bills) {
            switch (bill) {
                case 5: {
                    count5++;
                    break;
                }
                case 10: {
                    if (0 == count5) {
                        return false;
                    }
                    count5--;
                    count10++;
                    break;
                }
                case 20: {
                    int left = 15;
                    if (count10 > 0) {
                        left -= 10;
                        count10--;
                    }
                    int count5Needed = left / 5;
                    count5 -= count5Needed;
                    if (count5 < 0) {
                        return false;
                    }
                    break;
                }
            }
        }
        return true;
    }
};