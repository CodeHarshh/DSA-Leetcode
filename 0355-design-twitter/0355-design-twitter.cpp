class Twitter {
public:
    struct tweet {
        int tweetid;
        int time;

        tweet(int id, int t) {
            tweetid = id;
            time = t;
        }
    };

    int time;
    // map userid to twwets
    unordered_map<int, vector<tweet>> tweetsMap;

    // map user id to follower
    unordered_map<int, unordered_set<int>> followingMap;

    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        tweetsMap[userId].push_back(tweet(tweetId, time++));
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        for (tweet t : tweetsMap[userId]) {
            pq.push(make_pair(t.time, t.tweetid));
        }

        for (int followeeId : followingMap[userId]) {
            for (tweet t : tweetsMap[followeeId]) {
                pq.push(make_pair(t.time, t.tweetid));
            }
        }

        vector<int> result;
        int count = 10;
        while (count > 0 && !pq.empty()) {
        result.push_back(pq.top().second); // adds the most recent tweet ID to the result vector.
            pq.pop();
            count--;
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return; // i cant follow my self
        followingMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followingMap.find(followerId) != followingMap.end()) {
            followingMap[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */