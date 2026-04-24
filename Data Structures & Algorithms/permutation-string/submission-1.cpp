class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> sourceMap;
        for (char ch: s1) {
            sourceMap[ch]++;
        }

        int l = 0;
        unordered_map<char, int> tempMap;
        for (size_t i = 0; i < s2.size(); i++) {
            char ch = s2[i];
            if (!sourceMap.contains(ch)) {
                tempMap.clear();
                l = i + 1;
                continue;
            }
            while (sourceMap[ch] == tempMap[ch]) {
                tempMap[s2[l]]--;
                l++;
            }
            tempMap[ch]++;
            cerr << i << "|" << l << endl;
            if (s1.size() == (i - l + 1)) {
                return true;
            }
        }
        return false;
    }
};
