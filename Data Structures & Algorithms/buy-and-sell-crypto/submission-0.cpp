class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentMin = prices[0];
        int maxProfit = 0;
        for (int price: prices) {
            maxProfit = max(maxProfit, price - currentMin);
            currentMin = min(currentMin, price);
        }
        return maxProfit;
    }
};
