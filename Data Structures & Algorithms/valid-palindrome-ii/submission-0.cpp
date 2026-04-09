class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        return isPalindromeSlice(s, left, right, false);
    }

private:
    bool isPalindromeSlice(const string& s, int left, int right, bool wasMistake)
    {
        while (left < right) {
            if (s[left] != s[right]) {
                if (wasMistake) {
                    return false;
                }
                return isPalindromeSlice(s, left+1, right, true) || isPalindromeSlice(s, left, right-1, true);
            }
            left++;
            right--;
        }
        return true;
    }
};