package LeetCode;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class MinCostToConnectAllPoints {

    // Time complexity: O(n^2logN), space complexity: O(N^2)
    public static void main(String[] args) {
        System.out.println(minCostConnectPoints(new int[][]{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}}));
        System.out.println(minCostConnectPoints(new int[][]{{3,12},{-2,5},{-4,1}}));
    }

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
