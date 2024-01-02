package LeetCode;

import java.util.*;

public class NetworkDelayTime {

    public static void main(String[] args) {
        System.out.println(networkDelayTime(new int[][]{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}, 4, 2));
        System.out.println(networkDelayTime(new int[][]{{1, 2, 1}}, 2, 1));
        System.out.println(networkDelayTime(new int[][]{{1, 2, 1}}, 2, 2));
    }

    // Time complexity: O(Elog(V)), space complexity: O(V + E)
    public static int networkDelayTime(int[][] times, int n, int k) {
        Map<Integer, HashMap<Integer, Integer>> adjList = new HashMap<>();
        for (int[] time : times) {
            adjList.putIfAbsent(time[0], new HashMap<>());
            adjList.get(time[0]).put(time[1], time[2]);
        }

        boolean[] seen = new boolean[n + 1];
        Queue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        minHeap.add(new int[]{k, 0});
        int delay = 0;
        while (!minHeap.isEmpty()) {
            int[] values = minHeap.poll();
            int node = values[0];
            int cost = values[1];
            if (seen[node]) {
                continue;
            }
            seen[node] = true;
            delay = cost;
            n--;
            if (adjList.containsKey(node)) {
                for (int next : adjList.get(node).keySet()) {
                    if(seen[next]) {
                        continue;
                    }
                    minHeap.offer(new int[]{next, cost + adjList.get(node).get(next)});
                }
            }
        }

        return n == 0 ? delay : -1;
    }
}
