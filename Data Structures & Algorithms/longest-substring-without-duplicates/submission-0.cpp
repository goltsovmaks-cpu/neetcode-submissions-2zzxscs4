class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        size_t maxLenght = 0;
        int left = 0;
        for (char ch: s) {
            while (window.contains(ch)) {
                window.erase(s[left]);
                left++;
            }
            window.insert(ch);
            maxLenght = max(maxLenght, window.size());
        }
        return maxLenght;
    }
};
