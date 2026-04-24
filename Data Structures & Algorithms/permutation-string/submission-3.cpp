class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> sourceMap;
        for (char ch: s1) {
            sourceMap[ch]++;
        }

        int l = 0;
        int itemsLeft = s1.size();
        unordered_map<char, int> tempMap;
        for (size_t i = 0; i < s2.size(); i++) {
            char ch = s2[i];
            if (!sourceMap.contains(ch)) {
                tempMap.clear();
                itemsLeft = s1.size();
                continue;
            }
            while (sourceMap[ch] == tempMap[ch]) {
                tempMap[s2[l]]--;
                l++;
                itemsLeft++;
            }
            tempMap[ch]++;
            itemsLeft--;
            if (0 == itemsLeft) {
                return true;
            }
        }
        return false;
    }
};