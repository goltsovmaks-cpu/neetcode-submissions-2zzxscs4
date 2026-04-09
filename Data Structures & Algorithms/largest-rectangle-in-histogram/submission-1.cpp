class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> prevHeighs; 

        int maxArea = 0;

        for (size_t i = 0; i < heights.size(); i++) {
            int lastRemovedX = i;
            while (!prevHeighs.empty() && prevHeighs.top().second > heights[i]) {
                lastRemovedX = prevHeighs.top().first;
                int currentArea = prevHeighs.top().second * (i - lastRemovedX); // == prev to remove(i - 1) - X + 1
                maxArea = max(maxArea, currentArea); 
                prevHeighs.pop();
            }

            if (prevHeighs.empty() || prevHeighs.top().second < heights[i]) {
                prevHeighs.emplace(lastRemovedX, heights[i]);
                continue;
            }
        }

        while (!prevHeighs.empty()) {
            int currentArea = prevHeighs.top().second * ((heights.size() - prevHeighs.top().first));
            maxArea = max(maxArea, currentArea); 
            prevHeighs.pop();
        }

        return maxArea;
    }
};
