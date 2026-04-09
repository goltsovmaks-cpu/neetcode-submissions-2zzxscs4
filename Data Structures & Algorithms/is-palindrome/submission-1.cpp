class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            char leftCh = towlower(s[left]);
            if (!isalnum(leftCh)) {
                left++;
                continue;
            }

            char rightCh = towlower(s[right]);
            if (!isalnum(rightCh)) {
                right--;
                continue;
            }

            if (leftCh != rightCh) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
