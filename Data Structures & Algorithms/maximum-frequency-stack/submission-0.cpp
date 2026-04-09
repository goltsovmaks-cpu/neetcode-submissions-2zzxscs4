class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        auto& freq = NumToFrequency_[val];
        freq++;

        if (FrequencyToNumbers_.size() < freq) {
            FrequencyToNumbers_.push_back({});
        }
        FrequencyToNumbers_[freq - 1].push_back(val);
    }
    
    int pop() {
        int val = FrequencyToNumbers_.back().back();
        NumToFrequency_[val]--;
        FrequencyToNumbers_.back().pop_back();
        if (FrequencyToNumbers_.back().empty()) {
            FrequencyToNumbers_.pop_back();
        }
        return val;
    }
private:
    unordered_map<int, int> NumToFrequency_;
    vector<vector<int>> FrequencyToNumbers_;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */