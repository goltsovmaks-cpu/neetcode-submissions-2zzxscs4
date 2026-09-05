class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue pq(nums.begin(), nums.begin() + k, std::greater<int>());

        for (int i = k; i < nums.size(); i++) {
            int num = nums[i];

            if (num > pq.top()) {
                pq.push(num);
                pq.pop();
            }
        }
        return pq.top();
    }
};
