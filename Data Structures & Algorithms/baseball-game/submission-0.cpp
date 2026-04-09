class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> scores;

        for (const string& op: operations) {
            if ("+" == op) {
                int prev1 = scores.top();
                scores.pop();

                int prev2 = scores.top();
                scores.pop();

                int current = prev1 + prev2;

                scores.push(prev2);
                scores.push(prev1);
                scores.push(current);

            } else if ("C" == op) {
                scores.pop();
            } else if ("D" == op) {
                int last = scores.top();
                scores.push(last * 2);
            } else {
                int score = stoi(op);
                scores.push(score);
            }
        }

        int sum = 0;
        while (!scores.empty()) {
            sum += scores.top();
            scores.pop();
        }
        return sum;
    }
};