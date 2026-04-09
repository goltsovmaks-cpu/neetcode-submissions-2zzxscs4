class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numbers;
        for (const auto& token: tokens) {
            if ("+" == token) {
                DoOperation(numbers, [] (int lhs, int rhs) {return lhs + rhs;});
            } else if ("-" == token) {
                DoOperation(numbers, [] (int lhs, int rhs) {return lhs - rhs;});
            } else if ("*" == token) {
                DoOperation(numbers, [] (int lhs, int rhs) {return lhs * rhs;});
            } else if ("/" == token) {
                DoOperation(numbers, [] (int lhs, int rhs) {return lhs / rhs;});
            } else {
                numbers.push(stoi(token));
            }
        }
        return numbers.top();
    }

    template <typename TFunc>
    void DoOperation(std::stack<int>& numbers, TFunc op)
    {
        int right = numbers.top();
        numbers.pop();
        int left = numbers.top();
        numbers.pop();

        int result = op(left, right);

        numbers.push(result);
    }
};
