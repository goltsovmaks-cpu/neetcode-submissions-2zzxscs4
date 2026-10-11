class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph; // from->to,weight
        for (auto& ticket: flights) {
            int from = ticket[0];
            int to = ticket[1];
            int price = ticket[2];
            graph[from].emplace_back(to, price);
        }

        int minPrice = INT_MAX;
        int stepsLeft = k + 1 + 1; // start, stop

        unordered_map<int, int> cache; // node, bestPrice;
        cache[src] = 0;
        
        while (stepsLeft > 0 && !cache.empty()) {
            unordered_map<int, int> tmp;
            for (auto [node, bestPrice]: cache) {
                if (node == dst) {
                    minPrice = min(minPrice, bestPrice);
                    continue;
                }

                for (auto [adj, weight] : graph[node]) {
                    int newPrice = bestPrice + weight;
                    auto it = tmp.find(adj);
                    if (tmp.end() == it || newPrice < it->second ) {
                        tmp[adj] = newPrice;
                    }
                }
            }

            cache = std::move(tmp);
            stepsLeft--;
        }

        return INT_MAX == minPrice ? -1 : minPrice;
    }
};
