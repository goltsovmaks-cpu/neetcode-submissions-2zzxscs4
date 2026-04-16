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

        const auto& values = valuesIt->second;

        int l = 0;
        int r = values.size() - 1;

        int idx = l;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (values[m].first == timestamp) {
                idx = m;
                break;
            }

            if (values[m].first < timestamp) {
                idx = m;
                l = m + 1;
            } else { 
                r = m - 1;
            }
        }

        return values[idx].second;

        // auto upper = std::ranges::upper_bound(valuesIt->second, timestamp,
        //     std::ranges::less{},
        //     [](const TVersionedValue& v) { return v.first; });

        // upper--;
        // return upper->second;
    }

private:
    using TVersionedValue = pair<int, string>;
    unordered_map<string, vector<TVersionedValue>> Storage_;
};
