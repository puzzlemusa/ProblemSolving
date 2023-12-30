package LeetCode;

import java.util.*;

class Twitter {

    private final Map<Integer, Set<Integer>> followers;
    private final Map<Integer, List<Map.Entry<Integer, Integer>>> feeds;

    private int time = 0;

    public Twitter() {
        followers = new HashMap<>();
        feeds = new HashMap<>();
    }

    // Time complexity: O(1)
    public void postTweet(int userId, int tweetId) {
        if (feeds.containsKey(userId)) {
            feeds.get(userId).add(Map.entry(tweetId, time++));
        } else {
            List<Map.Entry<Integer, Integer>> list = new ArrayList<>();
            list.add(0, Map.entry(tweetId, time++));
            feeds.put(userId, list);
        }
    }

    // Time complexity: O(nlogk), where n is the number of tweets, and k is the number of followers
    public List<Integer> getNewsFeed(int userId) {
        Queue<Map.Entry<Integer, Integer>> maxHeap = new PriorityQueue<>((a, b) -> (b.getValue() - a.getValue()));
        if (feeds.containsKey(userId)) {
            maxHeap.addAll(feeds.get(userId));
        }

        if (followers.containsKey(userId)) {
            for (Integer followerId : followers.get(userId)) {
                if (feeds.containsKey(followerId)) {
                    maxHeap.addAll(feeds.get(followerId));
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        int i = 0;
        while (!maxHeap.isEmpty() && i < 10) {
            result.add(maxHeap.poll().getKey());
            i++;
        }

        return result;
    }

    // Time complexity: O(1)
    public void follow(int followerId, int followeeId) {
        if (followers.containsKey(followerId)) {
            followers.get(followerId).add(followeeId);
        } else {
            Set<Integer> list = new HashSet<>();
            list.add(followeeId);
            followers.put(followerId, list);
        }
    }

    // Time complexity: O(1)
    public void unfollow(int followerId, int followeeId) {
        if (followers.containsKey(followerId)) {
            Set<Integer> f = this.followers.get(followerId);
            f.remove(followeeId);
            followers.put(followerId, f);
        }
    }
}

public class DesignTwitter {

    public static void main(String[] args) {
        Twitter twitter1 = new Twitter();
        twitter1.postTweet(1, 5);
        System.out.println(twitter1.getNewsFeed(1));
        twitter1.follow(1, 2);
        twitter1.postTweet(2, 6);
        System.out.println(twitter1.getNewsFeed(1));
        twitter1.unfollow(1, 2);
        System.out.println(twitter1.getNewsFeed(1));
    }
}
