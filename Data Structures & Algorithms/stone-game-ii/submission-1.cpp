class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        TCache cache(piles.size() + 1, vector<optional<int>>(piles.size() + 1));
        vector<int> postSum(piles.size() + 1, 0);
        for (int i = piles.size() - 1; i >=0; i--) {
            postSum[i] = piles[i] + postSum[i+1];
        }
        return dfs(piles, 0, 1, postSum, cache);
    }
private:
    using TCache = vector<vector<optional<int>>>;

    int dfs(vector<int>& piles, int start, int m, const vector<int>& postSum, TCache& cache) {
        if (piles.size() == start) {
            return 0;
        }
        int end = min((int)piles.size(), start + (2 * m));
        if (cache[start][end].has_value()) {
            return *cache[start][end];
        }

        int sum = 0;

        for (int i = start; i < end; i++) {
            int nextM = max(m, i - start + 1);
            int maxForOpponent = dfs(piles, i + 1, nextM, postSum, cache);
            sum = max(sum, postSum[start] - maxForOpponent);
        }
        cache[start][end] = sum;
        return sum;
    }
};





















