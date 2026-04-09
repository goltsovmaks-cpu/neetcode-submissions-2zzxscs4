class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        values.push(val);

        int bestMin = val;
        if (!minValue.empty()) {
            bestMin = std::min(minValue.top(), val);
        }
        minValue.push(bestMin);
    }
    
    void pop() {
        values.pop();
        minValue.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return minValue.top();
    }
private:
    std::stack<int> values;
    // Fill at the same time as value but represent the smallest prev element for this position 
    std::stack<int> minValue; 
};
