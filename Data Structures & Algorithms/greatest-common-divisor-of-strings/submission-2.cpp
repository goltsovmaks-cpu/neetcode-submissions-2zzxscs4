#include <numeric>

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int gcd = std::gcd(str1.size(), str2.size());
        string result = str1.substr(0, gcd);
        auto hasDivisor = [&] (const string& str) { 
            for (int i = 0; i < str.size(); i++) {
                if (str[i] != result[i % gcd]) {
                    return false;
                }
            }
            return true;
        };
        
        return hasDivisor(str1) && hasDivisor(str2) ? result : "";
    }
};