class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        auto& bucket = GetBucket(key);
        auto it = ranges::find_if(bucket, [&] (const auto& item) {
            return item.first == key;
        });
        if (it != bucket.end()) {
            it->second = value;
            return;
        }
        bucket.push_back({key, value});
        if (bucket.size() >= BucketSize) {
            Balance();
        }
    }
    
    int get(int key) {
        const auto& bucket = GetBucket(key);
        auto it = ranges::find_if(bucket, [&] (const auto& kv) {
            return kv.first == key;
        });

        return it != bucket.end() ? it->second : -1;
    }
    
    void remove(int key) {
        auto& bucket = GetBucket(key);
        erase_if(bucket, [&](const auto& kv) {
            return kv.first == key;
        });
    }

private:
    using TKV = pair<int, int>;
    using TBucket = vector<TKV>;
    const int BucketSize = 10;
    const size_t INITIAL_STORAGE_SIZE = 1;
    vector<TBucket> Storage_{INITIAL_STORAGE_SIZE};
private:
    void Balance() {
        vector<TBucket> temp(Storage_.size() * 2);
        for (auto& bucket: Storage_) {
            for (auto& item: bucket) {
                int idx = item.first % temp.size();
                temp[idx].push_back(std::move(item));
            }
        }
        Storage_ = std::move(temp);
    }

    TBucket& GetBucket(int key) {
        return Storage_[key % Storage_.size()];
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */