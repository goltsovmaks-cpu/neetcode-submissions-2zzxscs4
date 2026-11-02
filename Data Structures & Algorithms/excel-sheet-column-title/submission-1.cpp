class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result; 
        while (columnNumber) {
            int mod = (columnNumber-1) % 26;

            char letter = 'A' + mod;
            result.push_back(letter);

            columnNumber = (columnNumber - 1) / 26;
        }
        ranges::reverse(result);
        return result;
    }
};