package LeetCode;

public class HouseRobber {
    public static void main(String[] args) {
        System.out.println(rob(new int[]{1, 2, 3, 1}));
        System.out.println(rob(new int[]{2, 7, 9, 3, 1}));
    }

    // Time complexity: O(n) | Space complexity: O(n)
    public static int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return Math.max(nums[0], nums[1]);
        } else if (n == 3) {
            return Math.max(nums[0] + nums[2], nums[1]);
        } else {
            int[] dp = new int[n];
            dp[0] = nums[0];
            dp[1] = nums[1];
            dp[2] = nums[2] + nums[0];
            for (int i = 3; i < n; i++) {
                dp[i] = Math.max(dp[i - 2], dp[i - 3]) + nums[i];
            }
            return Math.max(dp[n - 1], dp[n - 2]);
        }
    }

    // // Time complexity: O(n) | Space complexity: O(1)
    public int robDP1(int[] nums) {
        if (nums == null || nums.length == 0) return 0;

        int dp0 = 0, dp1 = 0, curr;

        for (int i = 0; i < nums.length; i++) {
            curr = Math.max(dp0 + nums[i], dp1);
            dp0 = dp1;
            dp1 = curr;
        }
        return Math.max(dp0, dp1);
    }
}
