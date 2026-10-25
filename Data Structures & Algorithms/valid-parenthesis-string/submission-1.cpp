class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char, int>> prevInfo;

        for (char ch: s) {
            pair<char, int> prev = {ch, 1};
            if (')' == ch) {
                if (prevInfo.empty()) {
                    return false;
                }
                prev = prevInfo.top();
                prevInfo.pop();
                if ('(' == prev.first || prevInfo.empty()) {
                    prev.second--;
                } else {
                    auto& open = prevInfo.top();
                    open.second--;
                    if (0 == open.second) {
                        prevInfo.pop();
                    }
                }
            }

            if (0 == prev.second) {
                continue;
            }

            if (!prevInfo.empty() && prevInfo.top().first == prev.first) {
                prevInfo.top().second += prev.second;
            } else {
                prevInfo.push(prev);
            }

            if (!prevInfo.empty()) {
                cerr << prevInfo.top().first << prevInfo.top().second << endl;
            }
        }

        int prevStarsCount = 0;
        while (!prevInfo.empty()) {
            auto p = prevInfo.top();
            cerr << p.first << p.second << endl;
            prevInfo.pop();
            if (p.first == '*') {
                prevStarsCount += p.second;
            } else {
                prevStarsCount -= p.second;
                if (prevStarsCount < 0) {
                    return false;
                }
            }
        }

        return true;
    }
};
