class Solution {
public:
    int countSubstrings(string s) {
        int count = s.size();

        for (int i = 0; i < s.size(); i++) {
            count += CountPalindroms(i, i + 1, s);
            count += CountPalindroms(i - 1, i + 1, s);
        }
        return count;
    }

    int CountPalindroms(int l, int r, const string& s) 
    {
        int count = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
            count++;
        }
        return count;
    }
};
