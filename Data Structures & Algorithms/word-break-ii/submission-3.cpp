#include <string_view>
#include <ranges>

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<vector<string_view>>> cache(n + 1);
        cache[n].push_back({});
        vector<bool> visited(n + 1, false);
        visited[n] = true;
        dfs(s, 0, wordDict, cache, visited);

        vector<string> result;
        result.reserve(cache[0].size());
        for (const auto& sentence : cache[0]) {
            result.push_back(
                sentence 
                | std::views::join_with(" "sv) 
                | std::ranges::to<std::string>()
            );
        }
        return result;
    }

    void dfs(
        string_view s,
        int i,
        const vector<string>& wordDict,
        vector<vector<vector<string_view>>>& cache,
        vector<bool>& visited)
    {
        if (visited[i]) {
            return;
        }

        for (const auto& word: wordDict) {
            if (!s.substr(i).starts_with(word)) {
                continue;
            }

            int nextToEndWord = i + word.size();
            dfs(s, nextToEndWord, wordDict, cache, visited);

            const auto& combinations = cache[nextToEndWord];
            if (combinations.empty()) {
                continue;
            }
            
            for (const auto& comb: combinations) {
                vector<string_view> current;
                current.reserve(comb.size() + 1);
                current.push_back(s.substr(i, word.size()));
                current.insert(current.end(), comb.begin(), comb.end());
                cache[i].push_back(std::move(current));
            }
        }
        visited[i] = true;
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



