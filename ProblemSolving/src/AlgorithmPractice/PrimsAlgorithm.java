package AlgorithmPractice;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class PrimsAlgorithm {

    // https://leetcode.com/problems/min-cost-to-connect-all-points/description/
    // Time complexity: O(n^2logN), space complexity: O(N^2)
    public static int minCostConnectPoints(int[][] points) {
        Queue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        boolean[] seen = new boolean[points.length];
        int added = 0;
        int totalCost = 0;
        minHeap.add(new int[]{0, 0});

        while (added < points.length) {
            int[] values = minHeap.poll();
            int index = values[0];
            int cost = values[1];
            if(seen[index]) {
                continue;
            }
            added++;
            totalCost += cost;
            seen[index] = true;

            for (int i = 0; i < points.length; i++) {
                if (seen[i]) {
                    continue;
                }
                minHeap.offer(new int[]{i, getDistance(points[index], points[i])});
            }
        }

        return totalCost;
    }

    private static int getDistance(int[] point1, int[] point2) {
        return Math.abs(point1[0] - point2[0]) + Math.abs(point1[1] - point2[1]);
    }
}
