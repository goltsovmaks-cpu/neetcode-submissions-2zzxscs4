class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int lastBestPrice = prices[0];
        int prevPrice = prices[0];
    
        int paintedProfit = 0;

        int actualProfit = 0;

        for (int price: prices) {
            if (price > prevPrice) {
                paintedProfit = price - lastBestPrice;
            }

            if (price < prevPrice) {
                actualProfit += paintedProfit;
                paintedProfit = 0;
                lastBestPrice = price;
            }
            prevPrice = price;
        }

        // In case last was biger.
        actualProfit += paintedProfit;

        return actualProfit;

    }
};