class Solution {
public:
    vector<vector<string>> partition(string s) {
        string word;
        return dfs(s, 0, word);
    }

    vector<vector<string>> dfs(const string& s, int startIndex, string& word) {
        if (s.size() == startIndex) {
            return {{}};
        }
        vector<vector<string>> result;
        for (int i = startIndex; i < s.size(); i++) {
            word.push_back(s[i]);
            if (isPalindrom(word)) {
                string tmp; 
                auto combinations = dfs(s, i + 1, tmp);
                for (auto& combination: combinations) {
                    combination.insert(combination.begin(), word);
                    result.push_back(std::move(combination));
                }
            }
        }
        return result;
    }

    bool isPalindrom(const string& s) {
        if (s.empty()) { return false; }
        int l = 0; int r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) { return false; } 
            l++; r--;
        }
        return true;
    }
};
