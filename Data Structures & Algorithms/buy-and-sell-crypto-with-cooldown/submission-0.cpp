class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector of size of 2.
        // [0] - best profite if we BUY on Ith day
        // [1] - best profite if we SELL on Ith day
        vector<vector<optional<int>>> cache(2, vector<optional<int>>(prices.size()));
        return dfs(prices, 0, false, cache);
    }

    int dfs(
        vector<int>& prices,
        int i,
        bool hasBought,
        vector<vector<optional<int>>>& cache
    ) {
        if (i >= prices.size()) {
            return 0;
        }
        if (cache[hasBought][i].has_value()) {
            return *cache[hasBought][i];
        }

        // hold 
        int best = dfs(prices, i+1, hasBought, cache);

        if (hasBought) { // try selling, is better?
            best = max(
                best,
                prices[i] + dfs(prices, i+2, false, cache)
            );
        } else { // try buying
            best = max(
                best,
                -prices[i] + dfs(prices, i + 1, true, cache)
            );
        }

        cache[hasBought][i] = best;
        return best;
    }
};














