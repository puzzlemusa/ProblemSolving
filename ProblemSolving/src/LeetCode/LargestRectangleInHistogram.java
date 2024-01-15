package LeetCode;


import java.util.ArrayDeque;
import java.util.Deque;

public class LargestRectangleInHistogram {

    public static void main(String[] args) {
        System.out.println(largestRectangleArea1(new int[]{2, 1, 5, 6, 2, 3}));
        System.out.println(largestRectangleArea1(new int[]{2, 4}));
        System.out.println(largestRectangleArea1(new int[]{5, 4, 3, 2, 1}));
    }

    // Monotonic Stack
    // Time: O(n), space: O(n)
    public static int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int res = 0;

        Deque<int[]> stk = new ArrayDeque<>();
        for (int i = 0; i < heights.length; i++) {
            int start = i;
            while (!stk.isEmpty() && stk.peek()[1] > heights[i]) {
                int[] top = stk.pop();
                res = Math.max(res, top[1] * (i - top[0]));
                start = top[0];
            }
            stk.push(new int[]{start, heights[i]});
        }

        while (!stk.isEmpty()) {
            int[] top = stk.pop();
            res = Math.max(res, top[1] * (n - top[0]));
        }

        return res;
    }

    public static int largestRectangleArea1(int[] heights) {
        int[] lessAtLeft = new int[heights.length];
        int[] lessAtRight = new int[heights.length];
        lessAtLeft[0] = -1;
        lessAtRight[heights.length - 1] = heights.length;

        for (int i = 1; i < heights.length; i++) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) {
                p = lessAtLeft[p];
            }
            lessAtLeft[i] = p;
        }

        for (int i = heights.length - 2; i >= 0; i--) {
            int p = i + 1;
            while (p < heights.length && heights[p] >= heights[i]) {
                p = lessAtRight[p];
            }
            lessAtRight[i] = p;
        }

        int res = 0;
        for (int i = 0; i < heights.length; i++) {
            res = Math.max(res, heights[i] * (lessAtRight[i] - lessAtLeft[i] - 1));
        }

        return res;
    }
}
