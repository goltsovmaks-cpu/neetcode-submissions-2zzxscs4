class Solution {
public:
    double myPow(double x, int n) {
        long long pow = n;
        double res = dfs(x, abs(pow));
        return n < 0 ? 1/res : res;
    }

    double dfs(double x, long long n) {
        if (0 == n) {
            return 1;
        }
        double res = 1;
        if (n & 1) {
            res = x;
        }
        double half = dfs(x, n/2);
        return res * half * half;
    // }

        // long long power = n;
        // power = abs(power);
        // double pow = n > 0 ? x : 1/x;
         
        // while (power != 0) {
        //     if (power & 1) {
        //         result *= pow;
        //     }
        //     pow *= pow; 
        //     power = power >> 1;
        // }

        // return result;
    }
};
