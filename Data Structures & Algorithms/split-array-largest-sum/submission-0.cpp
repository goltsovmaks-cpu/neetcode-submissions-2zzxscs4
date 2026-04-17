class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *ranges::max_element(nums);
        int r = std::accumulate(nums.begin(), nums.end(), 0);

        int ans = r;
        while (l <= r) {
            int m = l + (r - l) / 2;

            int currentK = 1;
            int currentLimit = m;
            for (int num: nums) {
                if (currentLimit - num < 0) {
                    currentK++;
                    currentLimit = m;
                }
                currentLimit -= num;
            }

            if (currentK > k) { // m - too small
                l = m + 1;
            } else { // with such m we could build k groups (or less) lets check if we decrease a little
                ans = min(ans, m);
                r = m - 1;
            }
        }
        return ans;
    }
};