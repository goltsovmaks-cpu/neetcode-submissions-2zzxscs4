#include <string_view>
#include <ranges>

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        vector<string> result;
        vector<string_view> path;
        dfs(s, wordDict, path, result);
        return result;
    }

    void dfs(
        string_view s,
        const vector<string>& wordDict,
        vector<string_view>& path,
        vector<string>& result)
    {
        if (s.empty()) {
            string joined = path 
                | std::views::join_with(" "sv) 
                | std::ranges::to<std::string>();
            result.push_back(joined);
            return;
        }

        for (const auto& word: wordDict) {
            if (s.starts_with(word)) {
                path.push_back(s.substr(0, word.size()));
                dfs(s.substr(word.size()), wordDict, path, result);
                path.pop_back();
            }
        }
    }
};



