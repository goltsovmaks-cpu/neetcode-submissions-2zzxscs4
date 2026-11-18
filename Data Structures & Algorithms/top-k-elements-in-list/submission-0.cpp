class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numToCount;
        for (int num: nums) {
            numToCount[num]++;
        }

        vector<vector<int>> counts(nums.size() +1);
        for (auto [num, count]: numToCount) {
            counts[count].push_back(num);
        }

        int left = k;
        vector<int> result;
        result.reserve(k);
        for (int i = nums.size(); i >=0; i--) {
            for (int num: counts[i]) {
                result.push_back(num);
                k--;
            }
            if (k <= 0) {
                break;
            }
        }
        return result;
    }
};
