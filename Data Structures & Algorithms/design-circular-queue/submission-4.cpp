class MyCircularQueue {
public:
    MyCircularQueue(int k)
        : Capacity_(k)
        , Storage_(k, 0)
    { }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        int idx = (First_ + Size_) % Capacity_;
        Storage_[idx] = value;
        Size_++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        First_ = (First_ + 1) % Capacity_;
        Size_--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return Storage_[First_];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        int idx = (First_ + Size_ - 1) % Capacity_;
        return Storage_[idx];
    }
    
    bool isEmpty() {
        return 0 == Size_;
    }
    
    bool isFull() {
        return Capacity_ == Size_;
    }

private:
    const int Capacity_;
    std::vector<int> Storage_;
    int First_ = 0;
    int Size_ = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */