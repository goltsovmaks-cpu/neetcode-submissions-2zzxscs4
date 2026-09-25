class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        const vector<int> expected = {
            (target[0] - '0'),
            (target[1] - '0'),
            (target[2] - '0'),
            (target[3] - '0')
        };

        auto tessaract = vector(
            10, vector<vector<vector<bool>>>(
                10, vector<vector<bool>>(
                    10, vector<bool>(10, false)
                )
            )
        );

        for (auto& v: deadends) {
            tessaract
                [(v[0] - '0')]
                    [(v[1] - '0')]
                        [(v[2] - '0')]
                            [(v[3] - '0')] = true;
        }

        queue<vector<int>> queue;
        auto tryAdd = [&] (vector<int> point)
        {
            for (int i = 0; i < point.size(); i++) {
                if (point[i] > 9) {
                    point[i] = 0;
                } else if (point[i] < 0) {
                    point[i] = 9;
                }
            }
            auto&& visited = tessaract[point[0]][point[1]][point[2]][point[3]];
            if (!visited) {
                queue.push(point);
                visited = true;
            }
        };
        tryAdd({0, 0, 0, 0});
        vector<vector<int>> directions = {
            {-1, 0, 0, 0},
            {1, 0, 0, 0},
            {0, -1, 0, 0},
            {0, 1, 0, 0},
            {0, 0, -1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, -1},
            {0, 0, 0, 1},
        };

        int height = 0;
        while (!queue.empty()) {
            int lenght = queue.size();
            for (int i = 0; i < lenght; i++) {
                if (expected == queue.front()) {
                    return height;
                }
                for (auto& dr: directions) {
                    auto point = queue.front();
                    point[0]+=dr[0];
                    point[1]+=dr[1];
                    point[2]+=dr[2];
                    point[3]+=dr[3];
                    tryAdd(point);
                }
                queue.pop();
            }
            height++;
        }

        return -1; 
    }
};









