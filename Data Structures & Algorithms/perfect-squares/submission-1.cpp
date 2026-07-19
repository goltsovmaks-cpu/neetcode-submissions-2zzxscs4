class Solution {
public:
    int numSquares(int n) {
        int bound = sqrt(n);

        vector<int> squares;
        squares.reserve(bound);

        for (int i = 1; i <= bound; i++) {
            squares.push_back(i * i);
        }

        vector<int> dp(n + 1, n + 1);
        for (int i = 1; i <= n; i++) {
            for (int sq: squares) {
                dp[sq] = 1;
                int idx = i - sq;
                if (idx < 0) {
                    break;
                }
                dp[i] = min(dp[i], 1 + dp[idx]);
            }
        }

        return dp.back();
    }
};