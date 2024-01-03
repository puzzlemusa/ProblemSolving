package LeetCode;

import java.util.Arrays;

public class ClimbingStairs {
    public static void main(String[] args) {
        System.out.println(climbStairs(1));
        System.out.println(climbStairs(2));
        System.out.println(climbStairs(8));
        System.out.println(climbStairs(45));
    }

    // Time complexity: O(n^2) | Space complexity: O(n)
    public static int climbStairs(int n) {
        int[] mem = new int[46];
        Arrays.fill(mem, -1);
        return calc(n, mem);
    }

    public static int calc(int n, int[] mem){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(mem[n] != -1){
            return mem[n];
        }
        return mem[n] = calc(n-1, mem) + calc(n-2, mem);
    }
}
