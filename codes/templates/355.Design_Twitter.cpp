/*
 * 355. Design Twitter
 * Medium
 ******************************************************************************
 * Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
 *
 * 1. postTweet(userId, tweetId): Compose a new tweet.
 * 2. getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
 * 3. follow(followerId, followeeId): Follower follows a followee.
 * 4. unfollow(followerId, followeeId): Follower unfollows a followee.
 ******************************************************************************
 * Example:
 *
 * Twitter twitter = new Twitter();
 *
 * // User 1 posts a new tweet (id = 5).
 * twitter.postTweet(1, 5);
 *
 * // User 1's news feed should return a list with 1 tweet id -> [5].
 * twitter.getNewsFeed(1);
 *
 * // User 1 follows user 2.
 * twitter.follow(1, 2);
 *
 * // User 2 posts a new tweet (id = 6).
 * twitter.postTweet(2, 6);
 *
 * // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
 * // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
 * twitter.getNewsFeed(1);
 *
 * // User 1 unfollows user 2.
 * twitter.unfollow(1, 2);
 *
 * // User 1's news feed should return a list with 1 tweet id -> [5],
 * // since user 1 is no longer following user 2.
 * twitter.getNewsFeed(1);
 *
 ******************************************************************************
 */

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>



class Twitter;
class Tweet
{
public:
    int      id;
    int    time;
    Tweet *next;
    Tweet(int id, int time):id(id),time(time),next(nullptr)
    {
    }
};

class User;
class User
{
public:
    int id;
    std::unordered_set<int> followed;
    Tweet *head;
    User(){}
    User(int userid):id(userid),head(nullptr)
    {
        follow(id);
    }

    void follow(int userid);
    void unfollow(int userid);
    void post(int tweetid);
};

class compare
{
public:
    bool operator()(Tweet * a, Tweet *b)
    {
        return a->time > b->time;
    }
};
class Twitter
{
    friend class Tweet;
    friend class User;
    std::unordered_map<int, User*> usermap;
public:
    static int timestamp ;
    /** Initialize your data structure here. */
    Twitter()
    {

    }

    /** Compose a new tweet. */
    void postTweet(int userid, int tweetid)
    {
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    std::vector<int> getNewsFeed(int userId)
    {
        return std::vector<int>();
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
    }
};

int Twitter::timestamp = 0;
void User::follow(int userid)
{
    followed.insert(userid);
}

void User::unfollow(int userid)
{
    if(this->id != userid)
    {
        followed.erase(userid);
    }
}
void User::post(int tweetid)
{
    Tweet *twt = new Tweet(tweetid, Twitter::timestamp);
    Twitter::timestamp++;
    twt->next = head;
    head = twt;
}

class Solution
{
public:
    //
    template <typename T>
    int printstack(std::stack<T> s)
    {
        if (s.empty())
        {
            std::cout << "The stack is empty." << std::endl;
            return 0;
        }
        std::cout <<  "The stack size is: " << s.size() << std::endl;
        std::stack<T> tmp;
        while (!s.empty())
        {
            std::cout << s.top() << ", ";
            s.pop();
        }
        std::cout <<  std::endl;
        return s.size();
    }

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| ";//<<std::endl;
        }
        std::cout << std::endl;
        return v.size();
    }

    template <typename T>
    int printvectorvector(const std::vector<T> &v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvector( *iter );
        }
        std::cout << std::endl;
        return v.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName
        )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Twitter* twitter = new Twitter();
    Solution* solution = new Solution();

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // getpermutataion
    {
        //start = std::chrono::system_clock::now();

        std::cout << "twitter 1 postTweet 5"<<std::endl;
        twitter->postTweet(1, 5);
        std::vector<int> result1 = twitter->getNewsFeed(1);
        solution->printvector(result1);

        std::cout << "twitter 1 follow 2: " << std::endl;
        twitter->follow(1, 2);

        std::cout << "twitter 2 postTweet 6: " << std::endl;
        twitter->postTweet(2, 6);
        std::vector<int> result2 = twitter->getNewsFeed(1);
        solution->printvector(result2);

        std::cout << "twitter 1 unfollow 2:" << std::endl;
        twitter->unfollow(1, 2);

        std::vector<int> result3 = twitter->getNewsFeed(1);
        solution->printvector(result3);

        //if(result1 == expected)
            std::cout << "Solution0 passed." << std::endl;
        //else
            std::cout << "Solution0 failed." << std::endl;
        //end = std::chrono::system_clock::now();
        //elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        //std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
    }
}
void Test1()
{
    Test("Test1");
}
void Test2()
{
}

void Test3()
{
}

void Test4()
{
}

void Test5()
{
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;

}
