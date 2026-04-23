class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charToCount;

        int maxLenght = 0;
        int l = 0;
        int maxF = 0;
        for (int i = 0; i < s.size(); i++) {
            charToCount[s[i]]++;
            maxF = max(maxF, charToCount[s[i]]);

            while ((i - l + 1) - maxF > k) {
            // while ((i - l + 1) - getMaxFreq(charToCount) > k) {
                charToCount[s[l]]--;
                l++;
            }
            maxLenght = max(maxLenght, i - l + 1);
        }
        return maxLenght;
    }

    // int getMaxFreq(const unordered_map<char, int>& map) {
    //     int mF = 0;
    //     for (const auto& [_, freq]: map) {
    //         mF = max(mF, freq);
    //     }
    //     return mF;
    // }
};
