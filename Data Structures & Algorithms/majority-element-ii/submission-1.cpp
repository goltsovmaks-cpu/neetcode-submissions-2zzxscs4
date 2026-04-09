class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int major1 = 0;

        int count2 = 0;
        int major2 = 0;

        for (int num: nums) {
            if (major1 == num) {
                count1++;
            } else if (major2 == num) {
                count2++;
            } else if (0 == count1) {
                count1++;
                major1 = num;
            } else if (0 == count2) {
                count2++;
                major2 = num;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> result;

        count1 = std::ranges::count(nums, major1);
        if (count1 > nums.size() / 3) {
            result.push_back(major1);
        }

        count2 = std::ranges::count(nums, major2);
        if (count2 > nums.size() / 3) {
            result.push_back(major2);
        }
        return result;
    }
};