package LeetCode;

import java.util.*;

public class TaskScheduler {
    public static void main(String[] args) {
        System.out.println(leastInterval(new char[]{'A', 'A', 'A', 'B', 'B', 'B'}, 2));
        System.out.println(leastInterval(new char[]{'A', 'A', 'A', 'B', 'B', 'B'}, 0));
        System.out.println(leastInterval(new char[]{'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'}, 2));
    }

    // Time complexity: O(nlogk), where n is the number of tasks and k is the number of unique tasks. Space complexity: O(k)
    public static int leastInterval(char[] tasks, int n) {
        Map<Character, Integer> mp = new HashMap<>();
        for (char task : tasks) {
            mp.put(task, mp.getOrDefault(task, 0) + 1);
        }

        Queue<Map.Entry<Character, Integer>> maxHeap = new PriorityQueue<>((a, b) -> (b.getValue() - a.getValue()));
        for (Map.Entry<Character, Integer> entry : mp.entrySet()) {
            maxHeap.offer(entry);
        }

        int time = 0;
        while (!maxHeap.isEmpty()) {
            List<Map.Entry<Character, Integer>> temp = new ArrayList<>();
            int i;
            for (i = 0; i <= n && !maxHeap.isEmpty(); i++) {
                Map.Entry<Character, Integer> entry = maxHeap.poll();
                entry.setValue(entry.getValue() - 1);
                if (entry.getValue() > 0) {
                    temp.add(entry);
                }
                time++;
            }
            if (!temp.isEmpty() && i <= n) {
                time += (n + 1 - i);
            }

            maxHeap.addAll(temp);
        }

        return time;
    }
}
