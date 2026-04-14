class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto& values = Storage_[key];
        if (values.empty() || values.back().second != value) {
            values.emplace_back(timestamp, value);
        }
    }
    
    string get(string key, int timestamp) {
        auto valuesIt = Storage_.find(key);
        if (Storage_.end() == valuesIt || valuesIt->second.front().first > timestamp) {
            return "";
        }

        auto upper = std::ranges::upper_bound(valuesIt->second, timestamp,
            std::ranges::less{},
            [](const TVersionedValue& v) { return v.first; });

        upper--;
        return upper->second;
    }

private:
    using TVersionedValue = pair<int, string>;
    unordered_map<string, vector<TVersionedValue>> Storage_;
};
