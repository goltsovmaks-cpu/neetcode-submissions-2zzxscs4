class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;

        for (int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case('*'):
                    star.push(i);
                    break;
                case('('):
                    open.push(i);
                    break;
                case(')'): {
                    if (!open.empty()) {
                        open.pop();
                    } else if (!star.empty()) {
                        star.pop();
                    } else {
                        return false;
                    }
                    break;
                }
            }
        }
        while (!open.empty()) {
            if (star.empty()) {
                return false;
            }

            int openIdx = open.top();
            open.pop();

            int starIdx = star.top();
            star.pop();
            if (starIdx < openIdx) {
                return false;
            }
        }
        return true;
    }

    // bool checkValidString(string s) {
    //     stack<pair<char, int>> prevInfo;

    //     for (char ch: s) {
    //         pair<char, int> prev = {ch, 1};
    //         if (')' == ch) {
    //             if (prevInfo.empty()) {
    //                 return false;
    //             }
    //             prev = prevInfo.top();
    //             prevInfo.pop();
    //             if ('(' == prev.first || prevInfo.empty()) {
    //                 prev.second--;
    //             } else {
    //                 auto& open = prevInfo.top();
    //                 open.second--;
    //                 if (0 == open.second) {
    //                     prevInfo.pop();
    //                 }
    //             }
    //         }

    //         if (0 == prev.second) {
    //             continue;
    //         }

    //         if (!prevInfo.empty() && prevInfo.top().first == prev.first) {
    //             prevInfo.top().second += prev.second;
    //         } else {
    //             prevInfo.push(prev);
    //         }
    //     }

    //     int prevStarsCount = 0;
    //     while (!prevInfo.empty()) {
    //         auto p = prevInfo.top();
    //         prevInfo.pop();
    //         if (p.first == '*') {
    //             prevStarsCount += p.second;
    //         } else {
    //             prevStarsCount -= p.second;
    //             if (prevStarsCount < 0) {
    //                 return false;
    //             }
    //         }
    //     }

    //     return true;
    // }
};
