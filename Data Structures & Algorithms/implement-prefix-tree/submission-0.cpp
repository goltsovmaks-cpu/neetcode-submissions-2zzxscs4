class PrefixTree {
public:
    PrefixTree() {
        DummyHead_ = new TNode();
    }
    
    void insert(string word) {
        if (word.empty()) {
            return;
        }

        TNode* curr = DummyHead_;
        int i = 0;

        while (i < word.size()) {
            char letter = word[i];
            auto it = ranges::find_if(curr->Childs, [&](const TNode* node) {
                return node->Letter == letter;
            });
            if (curr->Childs.end() == it) {
                TNode* node = new TNode();
                node->Letter = letter;
                curr->Childs.push_back(node);
                curr = node;
            } else {
                curr = *it;
            }
            i++;
        }
        curr->IsEndWord = true;
    }
    
    bool search(string word) {
        auto ptr = GetLastNode(word);
        return nullptr != ptr && ptr->IsEndWord;
    }
    
    bool startsWith(string prefix) {
        return GetLastNode(prefix) != nullptr;
    }

private:
    struct TNode {
        char Letter = '_';
        bool IsEndWord = false;
        vector<TNode*> Childs;
    };
    TNode* DummyHead_;

    // returns nullptr - if last letter doesnt exists
    TNode* GetLastNode(const string& word) {
        TNode* curr = DummyHead_;
        for (int i = 0; i < word.size(); i++) {
            char letter = word[i];
            auto it = ranges::find_if(curr->Childs, [&](const TNode* node) {
                return node->Letter == letter;
            });
            if (curr->Childs.end() == it) {
                return nullptr;
            }
            curr = *it;
        }
        return curr;
    }

};
