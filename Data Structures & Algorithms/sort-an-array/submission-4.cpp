class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<queue<int>> batches;
        for (int num: nums) {
            batches.emplace_back();
            batches.back().push(num);
        }

        while (batches.size() > 1) {
            vector<queue<int>> tmp;
            int i = 0;
            while (i < batches.size()) {
                auto first = std::move(batches[i]);
                i++;
                if (i < batches.size()) {
                    auto second = std::move(batches[i]);
                    tmp.push_back(merge(first, second));
                    i++;
                } else {
                    tmp.push_back(first);
                }
            }
            batches = std::move(tmp);
        }
        vector<int> result;
        auto& q = batches.front();

        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }

    queue<int> merge(queue<int>& first, queue<int>& second)
    {
        queue<int> result;
        while (!first.empty() || !second.empty()) {
            if (second.empty() || (!first.empty() && first.front() < second.front())) {
                result.push(first.front());
                first.pop();
            } else {
                result.push(second.front());
                second.pop();
            }
        }
        return result;
    }
    // void dfs(vector<int>& nums, int begin, int end)
    // {
    //     if (end - begin <= 1) {
    //         return;
    //     }

    //     int base = nums[end - 1];
    //     int left = begin;
    //     int right = end - 1;

    //     while (left < right) {
    //         if (nums[left] <= base) {
    //             left++;
    //         } else if (base < nums[right] ) {
    //             right--;
    //         } else {
    //             swap(nums[left], nums[right]);
    //         }
    //     }

    //     dfs(nums, begin, left);
    //     dfs(nums, left, end);
    // }
    // vector<int> sortArray(vector<int>& nums) {
    //     dfs(nums, 0, nums.size());
    //     return nums;
    // }

    // void dfs(vector<int>& nums, int begin, int end)
    // {
    //     if (end - begin <= 1) {
    //         return;
    //     }

    //     int firstGreater = begin;
    //     for (int i = begin; i < end - 1; i++) {
    //         if (nums[i] <= nums[end-1]) {
    //             swap(nums[i], nums[firstGreater]);
    //             firstGreater++;
    //         }
    //     }
    //     swap(nums[end-1], nums[firstGreater]);
        
    //     dfs(nums, begin, firstGreater);
    //     dfs(nums, firstGreater + 1, end);
    // }

};