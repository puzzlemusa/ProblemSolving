package LeetCode;

public class MinCostClimbingStairs {
    public static void main(String[] args) {
        System.out.println(minCostClimbingStairs(new int[]{10, 15, 20}));
        System.out.println(minCostClimbingStairs(new int[]{1, 100, 1, 1, 1, 100, 1, 1, 100, 1}));
    }

    public static int minCostClimbingStairs(int[] cost) {
        int[] mem = new int[1000];
        return Math.min(calc(cost, mem, 0), calc(cost, mem, 1));
    }

    public static int calc(int[] cost, int[] mem, int currStair) {
        if (currStair >= cost.length) {
            return 0;
        }
        if (mem[currStair] != 0) {
            return mem[currStair];
        }

        return mem[currStair] = Math.min((calc(cost, mem, currStair + 1) + cost[currStair]), (calc(cost, mem, currStair + 2) + cost[currStair]));
    }

    public static int minCostClimbingStairs1(int[] cost) {
        int[] dp = new int[cost.length];
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < cost.length; i++){
            cost[i] = Math.min(cost[i-1], cost[i-2]) + cost[i];
        }

        return Math.min(cost[cost.length -1], cost[cost.length -2]);
    }
}
