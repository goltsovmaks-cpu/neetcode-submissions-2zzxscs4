class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int lenght = q.size();
        q.push(x);
        for (int i = 0; i < lenght; i++) {
            q.push(q.front());
            q.pop();
        }   
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */