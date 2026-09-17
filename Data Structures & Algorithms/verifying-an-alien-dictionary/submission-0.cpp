class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i + 1 < words.size(); i++) {
            if (!isSorted(words[i], words[i+1], order)) {
                return false;
            }
        }
        return true;
    }

    bool isSorted(const string& lhs, const string& rhs, const string& order) {
        int limit = min(lhs.size(), rhs.size());
        for (int i = 0; i < limit; i++) {
            int lhsPos = ranges::find(order, lhs[i]) - order.begin();
            int rhsPos = ranges::find(order, rhs[i]) - order.begin();
            if (lhsPos != rhsPos) {
                return lhsPos < rhsPos;
            }
        }
        return lhs.size() <= rhs.size();
    }
};