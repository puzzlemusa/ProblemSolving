package LeetCode;


import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class PartitionEqualSubsetSum {
    public static void main(String[] args) {
        System.out.println(canPartition(new int[]{1, 5, 11, 5}));
        System.out.println(canPartition(new int[]{1, 2, 3, 5}));
        System.out.println(canPartition(new int[]{1, 1, 1}));
    }

    public static boolean canPartition(int[] nums) {
        Queue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        for (int num : nums) {
            maxHeap.offer(num);
        }

        int left = 0;
        int right = 0;
        while (!maxHeap.isEmpty()) {
            if (left < right) {
                left += maxHeap.poll();
            } else {
                right += maxHeap.poll();
            }
        }

        return left == right;
    }
}
