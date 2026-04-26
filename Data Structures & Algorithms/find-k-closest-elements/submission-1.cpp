class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int closestIdx = 0;

        auto leftCloser = [&] (int left, int right) {
            return abs(x - left) <= abs(x - right);
        };

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > x && leftCloser(arr[closestIdx], arr[i])) {
                break;
            }
            closestIdx = i;
        }

        int l = closestIdx;
        int r = closestIdx;
        int itemsLeft = k;
        itemsLeft--;
        while (itemsLeft > 0 && l > 0) {
            if (arr.size() - 1 == r) {
                l -= itemsLeft;
                break;
            }

            int left = arr[l-1];
            int right = arr[r+1];
            if (leftCloser(left, right)) {
                l--;
            } else {
                r++;
            }
            itemsLeft--;
        }

        return {arr.begin() + l, arr.begin() + l + k};
    }
};