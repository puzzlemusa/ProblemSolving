package LeetCode;


public class JumpGameII {

    public static void main(String[] args) {
        System.out.println(jump1(new int[]{2, 3, 1, 1, 4}));
        System.out.println(jump(new int[]{2, 3, 0, 1, 4}));
        System.out.println(jump(new int[]{0}));
        System.out.println(jump(new int[]{10, 0}));
    }

    // Time Complexity: O(n^2), space complexity: O(n)
    public static int jump(int[] nums) {
        if (nums.length == 1) {
            return 0;
        }
        int[] minJumps = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            minJumps[i] = Integer.MAX_VALUE;
        }

        return minJumps(nums, 0, minJumps);
    }

    private static int minJumps(int[] nums, int index, int[] minJumps) {
        if (index == nums.length - 1) {
            return 0;
        }

        if (index >= nums.length) {
            return nums.length;
        }

        if (minJumps[index] != Integer.MAX_VALUE) {
            return minJumps[index];
        }

        int min = nums.length;
        for (int i = 1; i <= nums[index]; i++) {
            min = Math.min(min, minJumps(nums, index + i, minJumps) + 1);
        }

        return minJumps[index] = min;
    }

    public static int jump1(int[] nums) {
        if (nums.length == 1) {
            return 0;
        }
        int jumps = 0;
        int farthest = 0;
        int lastJumped = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            farthest = Math.max(farthest, i + nums[i]);
            if (i == lastJumped) {
                jumps++;
                lastJumped = farthest;
            }
        }
        return jumps;
    }
}
