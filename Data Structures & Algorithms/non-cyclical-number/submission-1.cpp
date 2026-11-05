class Solution {
public:
    bool isHappy(int n) {
        auto next = [] (int num) {
            int sum = 0;
            while (num != 0) {
                int digit = num % 10;
                sum += digit * digit;
                num /= 10;
            }
            return sum;
        };

        int slow = n;
        int fast = next(n);

        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return slow == 1;
    }
};
