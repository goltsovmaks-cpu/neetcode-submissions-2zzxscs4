class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> valueWithIndex; // monotonic decreasing queue

        vector<int> ans;
        ans.reserve(nums.size() - k);
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            while (!valueWithIndex.empty() && valueWithIndex.back().first <= num) {
                valueWithIndex.pop_back();
            }
            valueWithIndex.emplace_back(num, i);

            if (i  - l + 1 < k) {
                continue;
            }

            if (valueWithIndex.front().second < l) {
                valueWithIndex.pop_front();
            }

            l++;
            ans.push_back(valueWithIndex.front().first);
        }
        return ans;
    }
};
