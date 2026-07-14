class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);
        dp.push_back(true);

        for (int i = s.size() - 1; i >=0; i--) {
            for (const string& word: wordDict) {
                if (i + word.size() > s.size()) {
                    continue;
                }
                if (!dp[i + word.size()]) {
                    continue;
                }

                if (s.substr(i, word.size()) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp.front();
    }
};
