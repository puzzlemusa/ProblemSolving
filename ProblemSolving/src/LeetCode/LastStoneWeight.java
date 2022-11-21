package LeetCode;


import java.util.Comparator;
import java.util.PriorityQueue;

public class LastStoneWeight {

    public static void main(String[] args) {
        System.out.println(lastStoneWeight(new int[]{2, 7, 4, 1, 8, 1}));
        System.out.println(lastStoneWeight(new int[]{1}));
    }

    public static int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> heap = new PriorityQueue<>(Comparator.reverseOrder());
        for (int stone : stones) {
            heap.add(stone);
        }

        while (heap.size() > 1) {
            Integer stone1 = heap.poll();
            Integer stone2 = heap.poll();

            if (stone1 != stone2) {
                heap.add(stone1 - stone2);
            }
        }

        return heap.isEmpty() ? 0 : heap.poll();
    }
}
