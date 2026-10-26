class Solution {
public:
    int candy(vector<int>& ratings) {

        vector<int> dp(ratings.size(), 1);

        auto iterate = [&] () {
            for (int i = 1; i < ratings.size(); i++) {
                if (ratings[i-1] < ratings[i]) {
                    dp[i] = max(dp[i], dp[i-1] + 1);
                }
            }
        };
        iterate();
        ranges::reverse(ratings);
        ranges::reverse(dp);
        iterate();

        return accumulate(dp.begin(), dp.end(), 0);

        // if (ratings.size() <= 1) {
        //     return ratings.size();
        // }

        // int count = 0;
        // auto getSumArifmetic = [&] (int a, int n) {
        //     cerr << a << n << endl;
        //     count += (a + a+n-1) * n / 2;
        // };

        // int start = 0;
        // int prev = ratings[0];
        // for (int i = 1; i < ratings.size(); i++) {
        //     if (ratings.size() == (i+1) || ratings[i] == ratings[i+1])  { 
        //         getSumArifmetic(1, i - start + 1);
        //         start = i + 1;
        //     } else if (prev < ratings[i] && ratings[i] > ratings[i+1]) {
        //         getSumArifmetic(1, i - start + 1); // not include ith // [1 2 3] 4 | 3...
        //         start = i + 1;
        //     } else if(prev > ratings[i] && ratings[i] < ratings[i+1]) {
        //         getSumArifmetic(2, i - start); // ...3 [4 3 2] 1
        //         start = i;
        //     }
        //     prev = ratings[i];
        // }
        // return count;
    }
};