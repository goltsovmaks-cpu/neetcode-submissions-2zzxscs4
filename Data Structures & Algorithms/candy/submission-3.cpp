class Solution {
public:
    int candy(vector<int>& ratings) {

        // vector<int> dp(ratings.size(), 1);
        // auto iterate = [&] () {
        //     for (int i = 1; i < ratings.size(); i++) {
        //         if (ratings[i-1] < ratings[i]) {
        //             dp[i] = max(dp[i], dp[i-1] + 1);
        //         }
        //     }
        // };
        // iterate();
        // ranges::reverse(ratings);
        // ranges::reverse(dp);
        // iterate();
        // ranges::reverse(ratings);
        // return accumulate(dp.begin(), dp.end(), 0);
        int result = ratings.size();
        int i = 1;
        while (i < ratings.size()) {
            if (ratings[i-1] == ratings[i]) {
                i++;
                continue;
            }

            int inc = 0;
            while (i < ratings.size() && ratings[i-1] < ratings[i]) {
                i++;
                inc++;
                result +=inc;
            }
            int dec = 0;
            while (i < ratings.size() && ratings[i-1] > ratings[i]) {
                i++;
                dec++;
                result +=dec;
            }
            result = result - min(inc, dec);
        }
        return result;
    }
};