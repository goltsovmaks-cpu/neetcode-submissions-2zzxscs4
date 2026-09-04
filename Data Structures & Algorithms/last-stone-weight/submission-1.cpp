class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue q(stones.begin(), stones.end());
        while (q.size() > 1) {
            int stone1 = q.top();
            q.pop();
            int stone2 = q.top();
            q.pop();
            int left = stone1-stone2;
            if (0 != left) {
                q.push(left);
            }
        }

        return q.empty() ? 0 : q.top();
    }
};
