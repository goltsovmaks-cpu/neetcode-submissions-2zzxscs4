class LRUCache {
public:
    LRUCache(int capacity) 
        : Capacity_(capacity)
    { }
    
    int get(int key) {
        auto it = TouchKey(key);
        return Cache_.end() == it ? -1 : it->second; 
    }
    
    void put(int key, int value) {
        auto it = TouchKey(key);
        if (it != Cache_.end()) {
            it->second = value;
            return;
        }

        if (Cache_.size() == Capacity_) {
            auto toRemove = Cache_.front();
            KeyToListIt_.erase(toRemove.first);
            Cache_.pop_front();
        }

        Cache_.push_back({key, value});
        KeyToListIt_[key] = prev(Cache_.end());
    }
private:
    using TList = list<pair<int, int>>;
    TList Cache_;
    unordered_map<int, TList::iterator> KeyToListIt_;
    const int Capacity_;
private:
    TList::iterator TouchKey(int key) {
        if (!KeyToListIt_.contains(key)) {
            return Cache_.end();
        }
        
        auto it = KeyToListIt_[key];
        Cache_.push_back({it->first, it->second});
        Cache_.erase(it);
        
        it = prev(Cache_.end());
        KeyToListIt_[key] = it;
        return it;
    }
};
