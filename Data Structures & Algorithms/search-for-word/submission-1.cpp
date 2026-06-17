class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> used;
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                if (exist(board, row, col, word, used)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool exist(
        const vector<vector<char>>& board,
        int row, int col,
        string_view word,
        vector<pair<int,int>>& used)
    {
        if (word.empty()) {
            return true;
        }
        if (
            row < 0 || col < 0 ||
            row >= board.size() ||
            col >= board[row].size())
        {
            return false;
        }

        if (board[row][col] != word.front()) {
            return false;
        }
        pair<int,int> point(row, col);
        if (auto it = ranges::find(used, point); used.end() != it) {
            return false;
        }

        string_view newWord = word.substr(1);

        used.push_back(point);
        bool result = false;
        result = result || exist(board, row - 1, col, newWord, used);
        result = result || exist(board, row, col + 1, newWord, used);
        result = result || exist(board, row + 1, col, newWord, used);
        result = result || exist(board, row, col - 1, newWord, used);
        used.pop_back();

        return result;
    }
};












