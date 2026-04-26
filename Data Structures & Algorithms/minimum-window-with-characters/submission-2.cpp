class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> source;
        for (char ch: t) {
            source[ch]++;
        }

        int l = 0;
        unordered_map<char, int> temp;

        int bestL = -1;
        int bestR = s.size();

        int matches = 0;
        for (int i = 0; i < s.size(); i++) {
            const char ch = s[i];
            if (!source.contains(ch)) {
                continue;
            }
            temp[ch]++;
            if (source[ch] == temp[ch]) {
                matches++;
            }

            while (source.size() == matches) {
                int bestLenght = bestR - bestL + 1;
                int currentLengh = i - l + 1;
                if (currentLengh < bestLenght) {
                    bestL = l;
                    bestR = i;
                }

                char leftCh = s[l];

                if (source.contains(leftCh)) {
                    temp[leftCh]--;
                    if (temp[leftCh] < source[leftCh]) {
                        matches--;
                    }
                }
                l++;
            }
        }
        return -1 != bestL ? s.substr(bestL, bestR-bestL+1) : ""; 
    }
};
