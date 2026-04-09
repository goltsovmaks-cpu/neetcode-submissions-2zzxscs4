class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() || strs[0].empty()) {
            return "";
        }
        size_t lenght = 0;
        while (true) {
            char originLetter = strs[0][lenght];
            bool isAllTheSame = true;
            for (const auto& str: strs) {
                if (lenght < str.size()  && str[lenght] == originLetter) {
                    continue;
                }
                isAllTheSame = false;
                break;
            }
            if (isAllTheSame) {
                lenght++;
                continue;
            }
            break;
        }

        return strs[0].substr(0, lenght);
    }
};