class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> result;
        dfs(s, 0, path, result);
        return result;
    }

    void dfs(const string& s, int startIndex, vector<string>& path, vector<vector<string>>& out) {
        if (s.size() == startIndex) {
            out.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrom(s, startIndex, i)) {
                path.push_back(s.substr(startIndex,  i - startIndex + 1));
                dfs(s, i + 1, path, out);
                path.pop_back();
            }
        }
    }

    bool isPalindrom(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) { 
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
