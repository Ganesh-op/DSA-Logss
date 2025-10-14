struct Tweet{
    int time;
    int tweetId;
    Tweet(int t, int id): time(t), tweetId(id) {}
};

class Twitter {

private:
     int timestamp;
     unordered_map<int, vector<Tweet>> userTweets;
     unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].emplace_back(timestamp++, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;

        for(const Tweet& tweet : userTweets[userId]){
            maxHeap.emplace(tweet.time, tweet.tweetId);
        }

        for(int followeeId : following[userId]){
            for(const Tweet& tweet : userTweets[followeeId]){
                maxHeap.emplace(tweet.time, tweet.tweetId);
            }
        }
        
        vector<int> feed;
        int count = 0;
        while(!maxHeap.empty() && count < 10){
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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