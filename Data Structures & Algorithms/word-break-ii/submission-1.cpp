#include <string_view>
#include <ranges>

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> cache(s.size() + 1);
        cache[s.size()].push_back("");
        dfs(s, 0, wordDict, cache);
        return cache[0];
    }

    void dfs(
        const string& s,
        int i,
        const vector<string>& wordDict,
        vector<vector<string>>& cache)
    {
        if (s.size() == i || !cache[i].empty()) {
            return;
        }

        for (const auto& word: wordDict) {
            if (word != s.substr(i, word.size())) {
                continue;
            }
            int nextToEndWord = i + word.size();
            dfs(s, nextToEndWord, wordDict, cache);
            const auto& combinations = cache[nextToEndWord];
            if (combinations.empty()) {
                continue;
            }
            for (const auto& comb: combinations) {
                string current;
                current.reserve(word.size() + comb.size() + 1);
                current += word;
                if (!comb.empty()) {
                    current += " " + comb;
                }
                cache[i].push_back(std::move(current));
            }
        }
    }
};
// class Solution {
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
        
//         vector<string> result;
//         vector<string_view> path;
//         dfs(s, wordDict, path, result);
//         return result;
//     }

//     void dfs(
//         string_view s,
//         const vector<string>& wordDict,
//         vector<string_view>& path,
//         vector<string>& result)
//     {
//         if (s.empty()) {
//             string joined = path 
//                 | std::views::join_with(" "sv) 
//                 | std::ranges::to<std::string>();
//             result.push_back(joined);
//             return;
//         }

//         for (const auto& word: wordDict) {
//             if (s.starts_with(word)) {
//                 path.push_back(s.substr(0, word.size()));
//                 dfs(s.substr(word.size()), wordDict, path, result);
//                 path.pop_back();
//             }
//         }
//     }
// };



