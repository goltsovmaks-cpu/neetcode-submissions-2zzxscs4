class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool> isReachable(s.size(), false);
        isReachable[0] = true;
        int R = 1;
        for (int i = 0; i < s.size(); i++) {
            bool isAviable = '0' == s[i] && isReachable[i];
            if (!isAviable) {
                continue;
            }

            int left = max(i+minJump, R);
            int right = min(i+maxJump+1, int(s.size()));
            while (left < right) {
                isReachable[left] = true;
                left++;
            }
            R = right;
        }

        return '0' == s.back() && isReachable.back();
    }
};