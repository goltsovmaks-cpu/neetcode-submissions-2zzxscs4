class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> prevRow(text1.size() + 1, 0);
        for (char ch2: text2) {
            vector<int> currentRow(text1.size() + 1, 0);
            for (int i = 1; i <= text1.size(); i++) {
                currentRow[i] = max(currentRow[i-1], prevRow[i]);

                int shifted = i - 1;
                if (text1[shifted] == ch2) {
                    currentRow[i] = max(currentRow[i], 1 + prevRow[shifted]);
                }
            }
            prevRow = std::move(currentRow);
        }

        return prevRow.back();
    }
};
