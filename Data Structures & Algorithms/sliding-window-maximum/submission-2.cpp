class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> valueWithIndex; // monotonic decreasing queue

        vector<int> ans;
        ans.reserve(nums.size() - k);
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            while (!valueWithIndex.empty() && valueWithIndex.back().first <= num) {
                valueWithIndex.pop_back();
            }
            valueWithIndex.emplace_back(num, i);

            if (i < k - 1) {
                continue;
            }

            if (valueWithIndex.front().second < i - k + 1) {
                valueWithIndex.pop_front();
            }

            ans.push_back(valueWithIndex.front().first);
        }
        return ans;
    }
};
