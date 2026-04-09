class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if (people.empty()) {
            return 0;
        }
        ranges::sort(people);

        size_t left = 0;
        size_t right = people.size() - 1;

        int ans = 0;

        while (left < right) {
            int sum = people[left] + people[right];
            if (sum <= limit) {
                left++;
            }
            right--;
            ans++;
        }
        if (left == right) {
            ans++;
        }
        return ans;
    }
};