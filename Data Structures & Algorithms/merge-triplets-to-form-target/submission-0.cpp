class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> couldBuild(target.size());

        for (const auto& triplet: triplets) {
            bool isValid = true;
            for (int i = 0; i < triplet.size(); i++) {
                if (triplet[i] > target[i]) {
                    isValid = false;
                    break;
                }
            }
            if (!isValid) {
                continue;
            }

            for (int i = 0; i < triplet.size(); i++) {
                if (triplet[i] == target[i]) {
                    couldBuild[i] = true;
                }
            }
        }
        return ranges::all_of(couldBuild, [] (bool val) {return val;});
    }
};
