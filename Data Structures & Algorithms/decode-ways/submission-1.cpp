class Solution {
public:
    int numDecodings(string s) {
        vector<pair<int, bool>> dp(s.size(), {0, false});
        dp.emplace_back(1, true);
        return dfs(s, 0, dp);
    }

    int dfs(const string& s, int idx, vector<pair<int, bool>>& dp)
    {
        if (idx >= s.size()) {
            return 1;
        }

        if (dp[idx].second) {
            return dp[idx].first;
        }

        if ('0' == s[idx]) {
            return 0;
        }

        // take 1 symbol
        int ans = dfs(s, idx + 1, dp);

        // second choice, take 2 symbols
        if (idx + 1 < s.size()) {            
            bool ok = ('2' == s[idx]) && (s[idx+1] <= '6');
            ok = ok || '1' == s[idx];
            if (ok) {
                ans += dfs(s, idx + 2, dp);
            }
        }
        dp[idx] = {ans, true};
        return ans;
    }
};








