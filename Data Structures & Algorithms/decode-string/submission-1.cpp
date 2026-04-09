class Solution {
public:
    string decodeString(string s) {
        string result;
        stack<pair<int, string>> countWithPrefix;

        int count = 1;
        string prefix;
        for (size_t i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) { // flush last patterns
                countWithPrefix.emplace(count, prefix);
                prefix = "";

                size_t len;
                count = stoi(&s[i], &len);
                i += len; // skip '['
                continue;
            }

            if (']' == s[i]) {
                string newString;
                while (0 != count) {
                    newString += prefix;
                    count--;
                }

                prefix = countWithPrefix.top().second += newString;
                count = countWithPrefix.top().first;
                countWithPrefix.pop();

                if (countWithPrefix.empty()) {
                    result += prefix;
                    prefix = "";
                    count = 1;
                }
            } else {
                prefix += s[i];
            }
        }
        if (!prefix.empty()) {
            result += prefix;
        }
        return result;
    }
};