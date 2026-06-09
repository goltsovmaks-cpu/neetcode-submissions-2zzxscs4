class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> path;
        return subsetXorSum(nums, 0, path);
    }

    int subsetXorSum(vector<int>& nums, int idx, vector<int>& path) {
        int res = 0;
        if (nums.size() == idx) {
            return std::accumulate(path.begin(), path.end(), 0, std::bit_xor<>());
        }
        // 1 chose -> take this num.
        path.push_back(nums[idx]);
        idx++;
        res += subsetXorSum(nums, idx, path);

        // 2 chose -> do not take this num.
        path.pop_back();
        res += subsetXorSum(nums, idx, path);
        return res;
    }
};