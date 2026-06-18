class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> result;
        string path;
        dfs(digits, 0, path, result);
        return result;
    }

    void dfs(const string& digits, int index, string& path, vector<string>& out) {
        if (digits.size() == index) {
            out.push_back(path);
            return;
        }

        for (char ch: Vocabulary_.at(digits[index])) {
            path.push_back(ch);
            dfs(digits, index + 1, path, out);
            path.pop_back();
        }
    }
private:
    const unordered_map<char, vector<char>> Vocabulary_ = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };

};
