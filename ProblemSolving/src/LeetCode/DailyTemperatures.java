package LeetCode;


import java.util.Arrays;
import java.util.Stack;

public class DailyTemperatures {

    public static void main(String[] args) {
        System.out.println(Arrays.toString(dailyTemperatures(new int[]{73, 74, 75, 71, 69, 72, 76, 73})));
        System.out.println(Arrays.toString(dailyTemperatures(new int[]{30, 40, 50, 60})));
        System.out.println(Arrays.toString(dailyTemperatures(new int[]{30, 60, 90})));
    }

    // Time complexity: O(n), Space complexity: O(n)
    public static int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> stk = new Stack<>();
        int[] res = new int[temperatures.length];
        for (int i = 0; i < temperatures.length; i++) {
            while (!stk.isEmpty() && temperatures[i] > temperatures[stk.peek()]) {
                int idx = stk.pop();
                res[idx] = i - idx;
            }
            stk.push(i);
        }

        return res;
    }
}
