class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TNode* curr = &DummyHead_;
        for (char letter: word) {
            auto it = curr->Children.find(letter);
            if (curr->Children.end() == it) {
                TNode* node = new TNode();
                curr->Children[letter] = node;
                curr = node;
            } else {
                curr = it->second;
            }
        }
        curr->IsEndWord = true;
    }
    
    bool search(string word) {
        queue<TNode*> parents;
        parents.push(&DummyHead_);
        int idx = 0;
        while (!parents.empty() && idx < word.size()) {
            int lenght = parents.size();
            const char letter = word[idx];

            for (int i = 0; i < lenght; i++) {
                const auto& node = parents.front();
                if ('.' == letter) {
                    for (const auto& [_, child]: node->Children) {
                        parents.push(child);
                    }
                } else if (auto it = node->Children.find(letter); node->Children.end() != it ) {
                    parents.push(it->second);
                }
                parents.pop();
            }
            idx++;
        }
        while (!parents.empty()) {
            const auto& node = parents.front();
            if (node->IsEndWord) {
                return true;
            }
            parents.pop();
        }
        return false;
    }
private:
    struct TNode {
        bool IsEndWord = false;
        unordered_map<char, TNode*> Children;
    };
    TNode DummyHead_;
};
