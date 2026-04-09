class MyHashSet {
public:
    MyHashSet()
        :  Store_(StoreSizeLimit)
    { }
    
    void add(int key) {
        if (contains(key)){
            return;
        }
        int bucketKey = GetBucketKey(key);
        Store_[bucketKey].Items.push_back(key);

        if (Store_[bucketKey].Items.size() == BucketLImit) {
            Rebalance();
        }
    }
    
    void remove(int key) {
        int bucketKey = GetBucketKey(key);
        std::erase(Store_[bucketKey].Items, key);
    }
    
    bool contains(int key) {
        int bucketKey = GetBucketKey(key);
        for (const int item: Store_[bucketKey].Items) {
            if (item == key) {
                return true;
            }
        }
        return false;
    }
private:
    int GetBucketKey(int key) const {
        return key % Store_.size();
    }

    void Rebalance() {
        std::vector<int> tempStore;
        tempStore.reserve(StoreSizeLimit * BucketLImit);

        for (const auto& bucket: Store_) {
            for (const int item: bucket.Items) {
                tempStore.push_back(item);
            }
        }
        Store_.clear();

        StoreSizeLimit *= 2;
        BucketLImit *=  2;

        Store_.assign(StoreSizeLimit, {});
        for (int item: tempStore) {
            add(item);
        }
    }
private:
    size_t StoreSizeLimit = 10;
    size_t BucketLImit = 10;
    struct TBucket {
        vector<int> Items;
    };
    vector<TBucket> Store_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */