class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        backtracking(n, n, path, result);
        return result;
    }

    void backtracking(int openLeft, int closeLeft, string& path, vector<string>& out) {
        if (0 == openLeft && 0 == closeLeft) {
            out.push_back(path);
            return;
        }

        // First chose - open NOW!
        if (openLeft > 0) {
            path.push_back('(');
            backtracking(openLeft - 1, closeLeft, path, out);
            path.pop_back();
        }

        // Second chose -> close me if you dare.
        if (openLeft < closeLeft) {
            path.push_back(')');
            backtracking(openLeft, closeLeft - 1, path, out);
            path.pop_back();
        }
    }
};
