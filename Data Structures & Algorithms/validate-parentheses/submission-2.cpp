class Solution {
public:
    bool isValid(string s) {
        std::stack<char> bracket;
        for (char ch: s) {
            switch (ch) {
                case ')': {
                    if (!checkLast(bracket, '(')) {
                        return false;
                    }
                    break;
                }
                case '}': {
                    if (!checkLast(bracket, '{')) {
                        return false;
                    }
                    break;
                }
                case ']': {
                    if (!checkLast(bracket, '[')) {
                        return false;
                    }
                    break;
                }
                default: {
                    bracket.push(ch);
                    break;
                }
            }
        }
        return bracket.empty();
    }
private:
    bool checkLast(std::stack<char>& bracket, const char expected) {
        if (bracket.empty()) {
            return false;
        }
        const char last = bracket.top();
        if (last != expected) {
            return false;
        }
        bracket.pop();
        return true;
    }
};











