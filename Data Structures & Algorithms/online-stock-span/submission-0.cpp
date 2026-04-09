class StockSpanner {
public:
    StockSpanner() {
        Prices_.reserve(10000);
        Dp_.reserve(10000);
    }
    
    int next(int price) {
        int prevIdx = Prices_.size() - 1;
        int result = 1;

        while (prevIdx >= 0) {
            if (Prices_[prevIdx] <= price) {
                int daysLessBefore = Dp_[prevIdx];
                result += daysLessBefore;
                prevIdx -= daysLessBefore;
            } else {
                break;
            }
        }

        Prices_.push_back(price);
        Dp_.push_back(result);
        return result;
    }
private:
    vector<int> Prices_;
    vector<int> Dp_; // represent answers for prices.
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */