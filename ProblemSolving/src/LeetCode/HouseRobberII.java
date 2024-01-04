package LeetCode;

public class HouseRobberII {
    public static void main(String[] args) {
        System.out.println(rob(new int[]{2, 3, 2}));
        System.out.println(rob(new int[]{1, 2, 3, 1}));
        System.out.println(rob(new int[]{1, 2, 3}));
        System.out.println(rob(new int[]{2, 7, 9, 3, 1}));
    }

    public static int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }

        return Math.max(rob(nums, 0, nums.length - 2), rob(nums, 1, nums.length - 1));
    }

    private static int rob(int[] nums, int start, int end) {
        int rob1 = 0;
        int rob2 = 0;
        for (int i = start; i <= end; i++) {
            int temp = Math.max(rob2, rob1 + nums[i]);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
    }
}
