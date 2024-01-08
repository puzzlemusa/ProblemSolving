package LeetCode;


public class PartitionEqualSubsetSum {
    public static void main(String[] args) {
        System.out.println(canPartition1(new int[]{1, 5, 11, 5}));
        System.out.println(canPartition1(new int[]{1, 2, 3, 5}));
        System.out.println(canPartition1(new int[]{3, 3, 3, 4, 5}));
    }

    // Space complexity: O(n * target), Time complexity: O(n * target)
    public static boolean canPartition(int[] nums) {
        int sum = 0;
        for (int num : nums)
            sum += num;

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        boolean[][] dp = new boolean[nums.length + 1][target + 1];
        for (int i = 0; i <= nums.length; i++) {
            for (int currSum = 0; currSum <= target; currSum++) {
                if (i == 0 || currSum == 0) {
                    dp[i][currSum] = false;
                } else if (nums[i - 1] > currSum) {
                    dp[i][currSum] = dp[i - 1][currSum];
                } else if (nums[i - 1] == currSum) {
                    dp[i][currSum] = true;
                } else {
                    dp[i][currSum] = dp[i - 1][currSum] || dp[i - 1][currSum - nums[i - 1]];
                }
            }
        }

        return dp[nums.length][target];
    }

    // Space complexity: O(n * target), Time complexity: O(target)
    public static boolean canPartition1(int[] nums) {
        int sum = 0;
        for (int num : nums)
            sum += num;

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        boolean[] dp = new boolean[target + 1];
        for (int i = 1; i <= nums.length; i++) {
            for (int currSum = target; currSum >= 0; currSum--) {
                if (nums[i - 1] == currSum) {
                    dp[currSum] = true;
                } else if (nums[i - 1] < currSum) {
                    dp[currSum] = dp[currSum] || dp[currSum - nums[i - 1]];
                }
            }
        }

        return dp[target];
    }
}
