package LeetCode;


import java.util.PriorityQueue;
import java.util.Queue;

public class KthLargestElementInAStream {

    public static void main(String[] args) {
        KthLargest(3, new int[]{4, 5, 8, 2});
        System.out.println(add(3));
        System.out.println(add(5));
        System.out.println(add(10));
        System.out.println(add(9));
        System.out.println(add(4));
    }

    static int kVal;
    private static Queue<Integer> q;

    // Time complexity: O(n + nlogk), space complexity: O(k)
    public static void KthLargest(int k, int[] nums) {
        q = new PriorityQueue<>();
        kVal = k;
        for (int num : nums) {
            add(num);
        }
    }

    public static int add(int val) {
        if (q.size() == kVal) {
            if (q.peek() < val) {
                q.poll();
                q.offer(val);
            }
        } else {
            q.offer(val);
        }
        return q.peek();
    }
}
