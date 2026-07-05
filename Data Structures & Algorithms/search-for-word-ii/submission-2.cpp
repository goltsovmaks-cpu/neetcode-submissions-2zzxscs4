class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        RowCount_ = board.size();
        ColumnCount_ = board[0].size();

        InitDummyNode(words);

        vector<vector<bool>> path;
        for (int row = 0; row < RowCount_; row++) {
            path.emplace_back(ColumnCount_, false);
        }

        unordered_set<string> result;
        for (int row = 0; row < RowCount_; row++) {
            for (int col = 0; col < ColumnCount_; col++) {
                dfs(board, row, col, &DummyHead_, path, result);
            }
        }
        return {result.begin(), result.end()};
    }
private:
    struct TNode{
        unordered_map<char ,TNode*> Children;
        string Word;
    };

private:
    void dfs(
        const vector<vector<char>>& board,
        int row, 
        int col,
        TNode* curr,
        vector<vector<bool>>& path,
        unordered_set<string>& result) 
    {
        if (
            row < 0 || col < 0 || 
            row >= RowCount_ || col >= ColumnCount_ ||
            path[row][col])
        {
            return;
        }

        char letter = board[row][col];
        auto it = curr->Children.find(letter);
        if (curr->Children.end() == it) {
            return;
        }
        curr = it->second;
        if (!curr->Word.empty()) {
            result.insert(curr->Word);
        }

        path[row][col] = true;
        dfs(board, row + 1, col, curr, path, result);
        dfs(board, row - 1, col, curr, path, result);
        dfs(board, row, col + 1, curr, path, result);
        dfs(board, row, col - 1, curr, path, result);
        path[row][col] = false;
    }

    void InitDummyNode(vector<string>& words) {
        for (string& word: words) {
            TNode* curr = &DummyHead_;
            for (char letter: word) {
                auto [it, inserted] = curr->Children.try_emplace(letter, nullptr);
                if (inserted) {
                    it->second = new TNode();
                }
                curr = it->second;
            }
            curr->Word = std::move(word);
        }
    }


private:
    int RowCount_ = 0;
    int ColumnCount_ = 0;
    TNode DummyHead_;
};
