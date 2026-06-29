class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {

        vector<optional<int>> cache(s.size() + 1);
        cache[s.size()] = 0;
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        return dfs(s, 0, dict, cache);
    }

    int dfs(
        const string& s,
        int startIndex,
        const unordered_set<string>& dict,
        vector<optional<int>>& cache)
    {
        if (cache[startIndex].has_value()) {
            return *cache[startIndex];
        }

        int result = s.size() - startIndex;
        for (int i = startIndex; i < s.size(); i++) {
            result = min(result, (i - startIndex + 1) + dfs(s, i + 1, dict, cache));

            string substr = s.substr(startIndex, i - startIndex + 1);
            if (!dict.contains(substr)) {
                continue;
            }
            result = min(result, dfs(s, startIndex + substr.size(), dict, cache));
        }
        cache[startIndex] = result;
        return result;
    }
};