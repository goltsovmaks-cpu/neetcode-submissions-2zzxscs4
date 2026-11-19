class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        tempStack.push(x);
    }
    
    int pop() {
        Flush();
        int value = stackLikeQueue.top();
        stackLikeQueue.pop();
        return value;
    }
    
    int peek() {
        Flush();
        return stackLikeQueue.top();
    }
    
    bool empty() {
        Flush();
        return stackLikeQueue.empty();
    }
private:
    void Flush() {
        if (!stackLikeQueue.empty()) {
            return;
        }
        while (!tempStack.empty()) {
            stackLikeQueue.push(tempStack.top());
            tempStack.pop();
        }
    }
private:
    stack<int> stackLikeQueue;
    stack<int> tempStack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */