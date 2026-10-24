class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> maxIndices;
        for (int i = 0; i < s.size(); i++) {
            maxIndices[s[i]] = i;
        }

        vector<int> result;
        int start = 0;
        int R = 0;
        for (int i = 0; i < s.size(); i++) {
            int currentBorder = maxIndices[s[i]];
            R = max(R, currentBorder);
 
            if (i == R) { // final seq
                result.push_back(R - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};
