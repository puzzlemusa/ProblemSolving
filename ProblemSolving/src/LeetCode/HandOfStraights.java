package LeetCode;


import java.util.PriorityQueue;
import java.util.Queue;

public class HandOfStraights {

    public static void main(String[] args) {
        System.out.println(isNStraightHand(new int[]{12, 11, 10, 9, 8, 1}, 3));
        System.out.println(isNStraightHand(new int[]{1, 2, 3, 6, 2, 3, 4, 7, 8}, 3));
    }

    // Time: O(nlogn), Space: O(n)
    public static boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0) {
            return false;
        }

        Queue<Integer> minHeap = new PriorityQueue<>();
        for (int card : hand) {
            minHeap.offer(card);
        }

        while (!minHeap.isEmpty()) {
            int start = minHeap.poll();
            for (int i = 1; i < groupSize; i++) {
                if (minHeap.remove(start + i)) {
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}
