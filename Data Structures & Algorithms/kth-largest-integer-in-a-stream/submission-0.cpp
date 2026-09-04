class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
        : QueueSize_(k)
    {
        for (int num: nums) {
            add(num);
        }
    }

    int add(int val) {
        MinQueue_.push(val);
        if (MinQueue_.size() > QueueSize_) {
            MinQueue_.pop();
        }
        return MinQueue_.top();
    }

private:
    const int QueueSize_ = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> MinQueue_;
};
