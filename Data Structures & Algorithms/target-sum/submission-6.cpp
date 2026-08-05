class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp; // sum, count
        dp[0] = 1;
        for (int num: nums) {
            unordered_map<int,int> temp;

            for (const auto[sum, count]: dp) {
                temp[sum-num]+=count;
                temp[sum+num]+=count;
            }
            dp = std::move(temp);
        }

        return dp[target];



        // // index -> Ith num, 
        // // map<sum, countOfWays>
        // TCache cache(nums.size());
        // int res =  dfs(nums, 0, target, cache);
        // return res;
    }


// private:
//     using TCache = vector<unordered_map<int, int>>;
//     int dfs(vector<int>& nums, int i, int target, TCache& cache) {
//         if (nums.size() == i) {
//             return 0 == target ? 1 : 0;
//         }
//         if (cache[i].contains(target)) {
//             return cache[i][target];
//         }
//         int num = nums[i];

//         cache[i][target] = 
//             dfs(nums, i + 1, target - num, cache) +
//             dfs(nums, i + 1, target + num, cache);


//         return cache[i][target];
//     }
};
