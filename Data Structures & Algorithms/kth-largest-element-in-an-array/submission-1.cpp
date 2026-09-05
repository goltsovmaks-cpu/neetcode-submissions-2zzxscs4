class Solution {
public:
    // quick select
    int findKthLargest(vector<int>& nums, int k) {
        return dfs(nums, 0, nums.size(), nums.size() - k);
    }

    int dfs(vector<int>& nums, int l, int r, int k) {
        int pivot = nums[r-1];
        int pos = l;

        for (int i = l; i < r; i++) {
            if (nums[i] <= pivot) {
                swap(nums[pos], nums[i]);
                pos++;
            }
        }
        pos--;
        if (pos == k) {
            return nums[k];
        } else if (pos < k) {
            return dfs(nums, pos+1, r, k);
        } else {
            return dfs(nums, l, pos, k);
        }
    }
};

// int findKthLargest(vector<int>& nums, int k) {
//     priority_queue pq(nums.begin(), nums.begin() + k, std::greater<int>());

//     for (int i = k; i < nums.size(); i++) {
//         int num = nums[i];

//         if (num > pq.top()) {
//             pq.push(num);
//             pq.pop();
//         }
//     }
//     return pq.top();
// }
