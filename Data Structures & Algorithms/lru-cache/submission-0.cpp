class LRUCache {
public:
    LRUCache(int capacity) 
        : Capacity_(capacity)
    { }
    
    int get(int key) {
        if (TouchValue(key)) {
            return KvQueue_.back().second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (TouchValue(key)) {
            KvQueue_.back().second = value;
            return;
        }

        if (Capacity_ == KeyToQueueIt_.size()) {
            int keyToRemove = KvQueue_.front().first;
            KvQueue_.pop_front();
            KeyToQueueIt_.erase(keyToRemove);
        }

        KvQueue_.emplace_back(key, value);
        KeyToQueueIt_[key] = prev(KvQueue_.end());
                
    }
private:
    bool TouchValue(int key) {
        const auto it = KeyToQueueIt_.find(key);
        if (KeyToQueueIt_.end() != it) {
            auto queueIt = it->second;
            int value = queueIt->second;
            KvQueue_.erase(queueIt);
            KvQueue_.emplace_back(key, value);
            KeyToQueueIt_[key] = prev(KvQueue_.end());
            return true;
        }
        return false;
    }
private:
    using TKVQueue = std::list<pair<int,int>>;
    const int Capacity_;
    TKVQueue KvQueue_;
    std::unordered_map<int, TKVQueue::iterator> KeyToQueueIt_;
};
