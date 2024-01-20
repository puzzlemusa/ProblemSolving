package LeetCode;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class SwimInRisingWater {
    public static void main(String[] args) {
        System.out.println(swimInWater(new int[][]{{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}}));
        System.out.println(swimInWater(new int[][]{{0, 2}, {1, 3}}));
    }

    // Time complexity: O(N^2logN), space complexity: O(N^2)
    public static int swimInWater(int[][] grid) {
        Queue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[2]));
        minHeap.offer(new int[]{0, 0, grid[0][0]});
        int res = 0;
        int[][] dirs = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        boolean[][] seen = new boolean[grid.length][grid[0].length];
        seen[0][0] = true;
        while (!minHeap.isEmpty()) {
            int[] curr = minHeap.poll();
            res = Math.max(res, curr[2]);
            if (curr[0] == grid.length - 1 && curr[1] == grid[0].length - 1) {
                break;
            }
            for (int[] dir : dirs) {
                int x = curr[0] + dir[0];
                int y = curr[1] + dir[1];
                if (x < 0 || x > grid.length - 1 || y < 0 || y > grid[0].length - 1 || seen[x][y]) {
                    continue;
                }
                minHeap.offer(new int[]{x, y, grid[x][y]});
            }
            seen[curr[0]][curr[1]] = true;
        }

        return res;
    }
}
