class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int startIndex = 0;
        int lenght = 1;

        auto updateBestPalindrom = [&] (int l, int r) { 
            auto info = FindLongestPalindrom(l, r, s);
            if (info.second > lenght) {
                startIndex = info.first;
                lenght = info.second;
            }
        };
        
        for (size_t i = 1; i < s.size(); i++) {
            updateBestPalindrom(i - 1, i);
            updateBestPalindrom(i - 1, i + 1);
        }

        return s.substr(startIndex, lenght);
    }

    // startIndex, lenght
    pair<int,int> FindLongestPalindrom(int l, int r, const string& s)
    {
        while (
            l >= 0 && r < s.size()
            && s[l] == s[r]
        ) {
            l--;
            r++;
        }
        l++;
        r--;
        return {l, r - l + 1};
    }
};









