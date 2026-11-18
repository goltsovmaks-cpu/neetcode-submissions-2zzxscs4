class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique;
        for (int num: nums) {
            unique.insert(num);
        }

        int maxLenght = 0;
        while (!unique.empty()) {
            int num = *unique.begin();
            unique.erase(num);

            int right = num;
            while (unique.erase(right + 1)) {
                right++;
            }

            int left = num;
            while(unique.erase(left - 1)) {
                left--;
            }

            maxLenght = max(maxLenght, right - left + 1);
        }

        return maxLenght;
    }
};
