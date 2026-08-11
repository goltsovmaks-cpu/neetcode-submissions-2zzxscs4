class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> dp(s.size() + 1, 1);

        for (int i = t.size() -1; i>=0; i--) {
            vector<int> temp(s.size() + 1, 0);
            for (int j = s.size() - 1; j >= 0; j--) {
                temp[j] = temp[j+1];
                if (s[j] == t[i]) {
                    temp[j] += dp[j+1];
                }
            }
            dp = std::move(temp);
        }
        return dp.front();
    }
};
