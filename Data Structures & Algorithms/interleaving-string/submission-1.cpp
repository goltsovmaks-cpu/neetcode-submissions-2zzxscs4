class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        TCache cache;
        bool couldLeave = dfs(s1, 0, s2, 0, s3, cache, true);
        couldLeave = couldLeave || dfs(s2, 0, s1, 0, s3, cache, false);
        return couldLeave;
    }
private:
    // s1(i), s2(j), takeFirst -> could bulid(bool).
    using TCache = unordered_map<int, unordered_map<int, unordered_map<bool, bool>>>;
    bool dfs(const string& s1, int i, const string& s2, int j, const string& s3, TCache& cache, bool takeFirst)
    {
        if (i + j == s3.size()) {
            return true;
        }
        if (cache.contains(i) && cache[i].contains(j) && cache[i][j].contains(takeFirst)) {
            return cache[i][j][takeFirst];
        }

        cache[i][j][takeFirst] = false;
        for (int k = i; k < s1.size(); k++) {
            if (s1[k] != s3[k + j]) {
                break;
            }
            if (dfs(s2, j, s1, k + 1, s3, cache, !takeFirst)) {
                cache[i][j][takeFirst] = true;
                break;
            }
        }
        return cache[i][j][takeFirst];
    }
};
