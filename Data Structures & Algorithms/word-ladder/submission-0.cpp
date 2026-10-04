class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> words;
        unordered_set<string> leftOvers(wordList.begin(), wordList.end());
        words.push(std::move(beginWord));
        leftOvers.erase(beginWord);
        int count = 1;

        auto collectWords = [&] (string word) {
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    word[i] = ch;
                    if (leftOvers.erase(word)) {
                        words.push(word);
                    }
                }
                word[i] = original;
            }
        };

        while (!words.empty()) {
            int lenght = words.size();
            for (int i = 0; i < lenght; i++) {
                string word = words.front();
                words.pop();
                if (word == endWord) {
                    return count;
                }
                collectWords(word);
            }
            count++;
        }
        return 0;
    }
};
