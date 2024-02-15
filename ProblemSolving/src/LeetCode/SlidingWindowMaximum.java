package LeetCode;


import java.util.*;

public class SlidingWindowMaximum {
    public static void main(String[] args) {
        System.out.println(Arrays.toString(maxSlidingWindow1(new int[]{1, 3, -1, -3, 5, 3, 6, 7}, 3)));
        System.out.println(Arrays.toString(maxSlidingWindow1(new int[]{1}, 1)));
        System.out.println(Arrays.toString(maxSlidingWindow1(new int[]{1, -1}, 1)));
        System.out.println(Arrays.toString(maxSlidingWindow1(new int[]{7, 2, 4}, 2)));
    }

    // TLE
    // Time: O(nlog(k)), Space: O(k)
    public static int[] maxSlidingWindow(int[] nums, int k) {
        Queue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            maxHeap.offer(nums[i]);
            if (i >= k) {
                maxHeap.remove(nums[i - k]);
            }
            if (i >= k - 1) {
                res.add(maxHeap.peek());
            }
        }

        return res.stream().mapToInt(i -> i).toArray();
    }

    // Time: O(n), Space: O(k)
    public static int[] maxSlidingWindow1(int[] nums, int k) {
        Deque<Integer> q = new ArrayDeque<>();
        int[] res = new int[nums.length - k + 1];
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (!q.isEmpty() && q.peek() <= i - k) {
                q.poll();
            }
            while (!q.isEmpty() && nums[q.peekLast()] < nums[i]) {
                q.pollLast();
            }
            q.offer(i);
            if (i >= k - 1) {
                res[j++] = nums[q.peek()];
            }
        }

        return res;
    }
}
