class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        auto it = std::remove(nums.begin(), nums.end(), val);
        return distance(nums.begin(), it);

        // size_t cur_to_find_from = 0;
        // size_t cur = 0;
        // while (cur < nums.size()) {

        //     if (val == nums[cur]) {
        //         cur_to_find_from = max(cur_to_find_from, cur);


        //         while (cur_to_find_from < nums.size() && val == nums[cur_to_find_from]) {
        //             ++cur_to_find_from;
        //         }

        //         if (cur_to_find_from == nums.size()) { // there is no good value to swap
        //             break;
        //         }

        //         swap(nums[cur], nums[cur_to_find_from]); 
        //     }
        //     ++cur;
        // }
        // return cur;
    }
};