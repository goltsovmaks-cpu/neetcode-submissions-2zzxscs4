class Solution {
public:
    struct TDsu {
        TDsu(int n)
            : Parents(n)
            , Ranks(n, 1)
        {
            ranges::iota(Parents, 0);
        }

        int Find(int curr) 
        {
            while (curr != Parents[curr]) {
                Parents[curr] = Parents[Parents[curr]];
                curr = Parents[curr];
            }
            return curr;
        }

        bool Union(int a, int b) {
            int parentA = Find(a);
            int parentB = Find(b);

            if (parentA == parentB) {
                return false;
            }

            if (Ranks[parentA] > Ranks[parentB]) {
                Ranks[parentA] += Ranks[parentB];
                Parents[parentB] = Parents[parentA];
            } else {
                Ranks[parentB] += Ranks[parentA];
                Parents[parentA] = Parents[parentB];
            }
            return true;
        }

        vector<int> Parents;
        vector<int> Ranks;
    };

    vector<int> findPrimalFactors(int num) {
        vector<int> result;
        for (int i = 2; i*i <= num; i++) {
            bool isFactor = false;
            while (num % i == 0) {
                num /= i;
                isFactor = true;
            }
            if (isFactor) {
                result.push_back(i);
            }
        }
        if (num > 1) {
            result.push_back(num);
        }
        return result;
    }


    bool canTraverseAllPairs(vector<int>& nums) {
        int itemsLeft = nums.size();
        TDsu dsu(itemsLeft);
        unordered_map<int, int> factorsToIndex; // factor, element 
        for (int i = 0; i < nums.size(); i++) {
            auto factors = findPrimalFactors(nums[i]);
            for (int factor: factors) {
                auto [it, inserted] = factorsToIndex.try_emplace(factor, i);
                if (inserted) {
                    continue;
                }
                itemsLeft -= dsu.Union(it->second, i);
            }
        }

        return 1 == itemsLeft;
    }
};













