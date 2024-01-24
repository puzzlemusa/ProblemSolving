package LeetCode;


import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class SingleThreadedCPU {
    public static void main(String[] args) {
        System.out.println(Arrays.toString(getOrder(new int[][]{{19, 13}, {16, 9}, {21, 10}, {32, 25}, {37, 4}, {49, 24}, {2, 15}, {38, 41}, {37, 34}, {33, 6}, {45, 4}, {18, 18}, {46, 39}, {12, 24}})));
        System.out.println(Arrays.toString(getOrder(new int[][]{{1, 2}, {2, 4}, {3, 2}, {4, 1}})));
        System.out.println(Arrays.toString(getOrder(new int[][]{{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}})));
    }

    // Time complexity: O(nlog(n)), space complexity: O(n)
    public static int[] getOrder(int[][] tasks) {
        int[][] tasksWithIndex = new int[tasks.length][3];
        for (int i = 0; i < tasks.length; i++) {
            tasksWithIndex[i][0] = tasks[i][0];
            tasksWithIndex[i][1] = tasks[i][1];
            tasksWithIndex[i][2] = i;
        }
        Arrays.sort(tasksWithIndex, Comparator.comparingInt(a -> a[0]));

        Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[1] == b[1] ? a[2] - b[2] : a[1] - b[1]);
        int[] res = new int[tasks.length];
        int k = 0;
        int i = 0;
        int currTime = tasksWithIndex[0][0];
        while (i < tasksWithIndex.length) {
            while (i < tasksWithIndex.length && tasksWithIndex[i][0] <= currTime) {
                minHeap.offer(new int[]{tasksWithIndex[i][0], tasksWithIndex[i][1], tasksWithIndex[i][2]});
                i++;
            }
            if (minHeap.isEmpty()) {
                currTime = tasksWithIndex[i][0];
                continue;
            }
            int[] nextTask = minHeap.poll();
            res[k++] = nextTask[2];
            currTime = currTime + nextTask[1];
        }
        while (!minHeap.isEmpty()) {
            int[] nextTask = minHeap.poll();
            res[k++] = nextTask[2];
        }

        return res;
    }
}
