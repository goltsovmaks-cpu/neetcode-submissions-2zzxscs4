class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 0; i < p.size(); i++) {
            if ('*' == p[i]) {
                continue;
            }

            bool hasStarNext = false;
            if (i+1 != p.size() && '*' == p[i+1]) {
                hasStarNext = true;
            }

            vector<bool> temp = hasStarNext ? dp : vector<bool>(s.size() + 1, false);

            for (int j = 0; j < s.size(); j++) {
                bool sameSymbol = s[j] == p[i] ||  '.' == p[i];
                bool ok = false;
                if (sameSymbol) {
                    ok = dp[j] || (hasStarNext && temp[j]);
                }
                temp[j+1] = temp[j+1] || ok;
            }

            dp = std::move(temp);
        }

        return dp.back();
    }
};
