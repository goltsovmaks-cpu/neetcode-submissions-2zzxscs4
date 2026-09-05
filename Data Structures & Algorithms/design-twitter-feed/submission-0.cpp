class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        UsersPost_[userId].emplace_back(tweetId, Counter_);
        Counter_++;
    }
    
    vector<int> getNewsFeed(int userId) {
        struct TItem {
            int UniqueId;
            int TweetId;
            int UserId;
            size_t PostIndex;
        };

        auto cmp = [] (const TItem& left, const TItem& right) {
            return right.UniqueId > left.UniqueId;
        };
        priority_queue<TItem, vector<TItem>, decltype(cmp)> pq(cmp);

        vector<int> sourceUsers(UsersLinks_[userId].begin(), UsersLinks_[userId].end());
        sourceUsers.push_back(userId);
        for (int userId: sourceUsers) {
            const auto& posts = UsersPost_[userId];
            if (posts.empty()) {
                continue;
            }
            pq.push({
                .UniqueId = posts.back().second,
                .TweetId = posts.back().first,
                .UserId = userId,
                .PostIndex = posts.size() - 1
            });
        }

        int left = 10;
        vector<int> result;
        while (left > 0 && !pq.empty()) {
            auto latest = pq.top();
            pq.pop();
            result.push_back(latest.TweetId);
            if (latest.PostIndex > 0) {
                int userId = latest.UserId;
                size_t index = latest.PostIndex - 1;
                const auto post = UsersPost_[userId][index];
                pq.push({
                    .UniqueId = post.second,
                    .TweetId = post.first,
                    .UserId = userId,
                    .PostIndex = index
                });
            }
            left--;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        UsersLinks_[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        UsersLinks_[followerId].erase(followeeId);
    }
private:
    unordered_map<int, vector<pair<int, int>>> UsersPost_;
    unordered_map<int, unordered_set<int>> UsersLinks_;
    int Counter_ = 0;
};
