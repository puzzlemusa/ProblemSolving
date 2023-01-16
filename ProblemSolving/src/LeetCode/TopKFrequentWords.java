package LeetCode;


import java.util.*;

public class TopKFrequentWords {

    public static void main(String[] args) {
        System.out.println(topKFrequent(new String[]{"i", "love", "leetcode", "i", "love", "coding"}, 2));
        System.out.println(topKFrequent(new String[]{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, 4));
    }

    public static List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> mp = new HashMap<>();
        for (String word : words) {
            mp.put(word, mp.getOrDefault(word, 0) + 1);
        }
        Queue<String> heap = new PriorityQueue<>((s1, s2) -> {
            if (mp.get(s1) == mp.get(s2)) {
                return s1.compareTo(s2);
            } else {
                return mp.get(s2) - mp.get(s1);
            }
        });
        heap.addAll(mp.keySet());

        List<String> res = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            res.add(heap.poll());
        }

        return res;
    }
}
