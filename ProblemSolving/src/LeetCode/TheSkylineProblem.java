package LeetCode;


import java.util.*;

public class TheSkylineProblem {

    public static void main(String[] args) {
        System.out.println(getSkyline(new int[][]{{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}}));
        System.out.println(getSkyline(new int[][]{{0,2,3},{2,5,3}}));
    }

    // Time complexity: O(n^2), space complexity: O(n). pq.remove(item) is O(n) in worst case.
    public static List<List<Integer>> getSkyline(int[][] buildings) {
        int[][] heights = new int[buildings.length * 2][2];
        int index = 0;
        for (int[] building : buildings) {
            heights[index++] = new int[]{building[0], building[2]};
            heights[index++] = new int[]{building[1], -1 * building[2]};
        }

        Arrays.sort(heights, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        Queue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        maxHeap.offer(0);
        List<List<Integer>> res = new ArrayList<>();
        int prev = 0;
        for (int[] height : heights) {
            if (height[1] > 0) {
                maxHeap.offer(height[1]);
            } else {
                maxHeap.remove(-1 * height[1]);
            }
            int cur = maxHeap.peek();
            if (cur != prev) {
                res.add(Arrays.asList(height[0], cur));
                prev = cur;
            }
        }

        return res;
    }
}
