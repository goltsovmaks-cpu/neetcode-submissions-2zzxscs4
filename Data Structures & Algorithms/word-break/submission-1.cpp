class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);
        dp.push_back(true);

        for (int i = s.size() - 1; i >=0; i--) {
            for (const string& word: wordDict) {
                int endPos = i + word.size();
                if (endPos > s.size() || !dp[endPos]) {
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
