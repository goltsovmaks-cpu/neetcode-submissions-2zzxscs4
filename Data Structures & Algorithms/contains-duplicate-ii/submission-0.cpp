class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (0 == k) {
            return false;
        }
        unordered_set<int> window;
        int l = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i - l > k) {
                window.erase(nums[l]);
                l++;
            }
            if (window.contains(nums[i])) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};