class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = height.front();
        int rightMax = height.back();;
        int left = 0;
        int right = height.size() - 1;

        int ans = 0;

        while (left < right) {
            int minLimit = min(leftMax, rightMax);
            int currentDelta = 0;
            if (leftMax < rightMax) {
                left++;
                currentDelta = minLimit - height[left];
                leftMax = max(leftMax, height[left]);
            } else {
                right--;
                currentDelta = minLimit - height[right];
                rightMax = max(rightMax, height[right]);
            }
            cerr << currentDelta << left << right << endl; 

            if (currentDelta > 0) {
                ans += currentDelta;
            }
        }
        return ans;
    }
};
