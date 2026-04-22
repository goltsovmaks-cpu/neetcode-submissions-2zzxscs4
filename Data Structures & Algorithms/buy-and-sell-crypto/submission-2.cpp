class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = prices[0];
        for (int price: prices) {
            profit = max(profit, price - minPrice);
            minPrice = min(minPrice, price);
        }
        return profit;
    }
};
