class LFUCache {
public:
    LFUCache(int capacity)
        : Capacity_(capacity) {
    }
    
    int get(int key) {
        if (!TouchItem(key)) {
            return -1;
        }
        return KeyToIt_[key]->Value;
    }

    void put(int key, int value) {
        if (TouchItem(key)) {
            KeyToIt_[key]->Value = value;
            return;
        }

        int newFrequency = 1;
        if (Capacity_ == KeyToIt_.size()) {
            const TItem& itemToDelete = FrequencyToChunk_[MinFrequency_].front();
            KeyToIt_.erase(itemToDelete.Key);
            FrequencyToChunk_[MinFrequency_].pop_front();
        }
        TItem item{
            .Key = key,
            .Value = value,
            .Frequency = newFrequency
        };
        PushItem(item);
    }
private:
    struct TItem {
        int Key = 0;
        int Value = 0;
        int Frequency = 0;
    };

private:
    bool TouchItem(int key)
    {
        auto it = KeyToIt_.find(key);
        if (KeyToIt_.end() == it) {
            return false;
        }

        TIt chunkIt = it->second;
        TItem item = *chunkIt;

        FrequencyToChunk_[item.Frequency].erase(chunkIt);

        item.Frequency++;
        PushItem(item);

        return true;
    }

    void UpdateMinFrequency(int newFrequency) {
        if (FrequencyToChunk_[MinFrequency_].empty() || newFrequency < MinFrequency_) {
            MinFrequency_ = newFrequency;
        }
    }

    void PushItem(const TItem& item) {
        FrequencyToChunk_[item.Frequency].push_back(item);
        KeyToIt_[item.Key] = prev(FrequencyToChunk_[item.Frequency].end());
        UpdateMinFrequency(item.Frequency);
    }

private:
    using TChank = std::list<TItem>;
    using TIt = TChank::iterator;

    unordered_map<int, TIt> KeyToIt_;
    unordered_map<int, TChank> FrequencyToChunk_;

    const int Capacity_;
    int MinFrequency_ = 0;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */