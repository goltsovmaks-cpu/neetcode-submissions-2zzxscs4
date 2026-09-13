class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty() || left.top() > num) {
            left.push(num);
        } else { 
            right.push(num);
        }

        // rebalance heaps
        if (left.size() < right.size()) { 
            left.push(right.top());
            right.pop();
        } else if (left.size() == right.size() + 2) {
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        } 
        return double(left.top() + right.top()) / 2.0;
    }
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, std::greater<int>> right;
};
