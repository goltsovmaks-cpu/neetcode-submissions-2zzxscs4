class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minPrice = prices[0];
        for (int price: prices) {
            if (price > minPrice) {
                ans = max(ans, price - minPrice);
            } else {
                minPrice = min(minPrice, price);
            }
        }
        return ans;
    }
};
