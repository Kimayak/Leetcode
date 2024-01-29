
// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

// Implement the Twitter class:

// Twitter() Initializes your twitter object.
// void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
// List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
// void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
// void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 

// Example 1:

// Input
// ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
// [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
// Output
// [null, null, [5], null, null, [6, 5], null, [5]]

// Explanation
// Twitter twitter = new Twitter();
// twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
// twitter.follow(1, 2);    // User 1 follows user 2.
// twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
// twitter.unfollow(1, 2);  // User 1 unfollows user 2.
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
 

// Constraints:

// 1 <= userId, followerId, followeeId <= 500
// 0 <= tweetId <= 104
// All the tweets have unique IDs.
// At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and unfollow.

class Twitter {
private: 
    struct Tweet{
        int tweetId;
        int time;

        Tweet(int id, int time) : tweetId(id), time(time) {}
    };

    unordered_map<int, list<Tweet>> tweets; 

    unordered_map<int, unordered_set<int>> following;

    int time;

public:
    Twitter() : time(0){
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_front(tweetId, time++);
        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<list<Tweet>::iterator, list<Tweet>::iterator>> h;
        for (auto& f : following[userId]) {
            if (!tweets[f].empty()) {
                h.emplace_back(tweets[f].begin(), tweets[f].end());
            }
        }
        if (!tweets[userId].empty()) {
            h.emplace_back(tweets[userId].begin(), tweets[userId].end());
        }

        vector<int> newsFeed;
        for (int i = 0; i < 10 && !h.empty(); ++i) {
            // Find the most recent tweet
            auto mostRecent = h.begin();
            for (auto it = h.begin(); it != h.end(); ++it) {
                if (it->first->time > mostRecent->first->time) {
                    mostRecent = it;
                }
            }
            newsFeed.push_back(mostRecent->first->tweetId);

            // Move the iterator forward
            if (++(mostRecent->first) == mostRecent->second) {
                h.erase(mostRecent);
            }
        }
        return newsFeed;
        
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