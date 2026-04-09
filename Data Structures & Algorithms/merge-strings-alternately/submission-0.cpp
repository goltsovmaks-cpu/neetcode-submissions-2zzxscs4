class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;

        size_t index = 0;

        size_t maxLenght = max(word1.size(), word2.size());
        result.reserve(maxLenght);

        while (index < maxLenght) {
            if (index < word1.size()) {
                result.push_back(word1[index]);
            }
            if (index < word2.size()) {
                result.push_back(word2[index]);
            }
            index++;
        }
        return result;
    }
};