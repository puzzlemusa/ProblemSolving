package LeetCode;


public class MaximumProductSubarray {

    public static void main(String[] args) {
        System.out.println(maxProduct(new int[]{-2, 0, -1}));
        System.out.println(maxProduct(new int[]{2, 3, -2, 4}));
        System.out.println(maxProduct(new int[]{-2, -3, -2, -2, 0, 2, 6, 4, 0}));
        System.out.println(maxProduct(new int[]{1, 3, 4, 2, 0, -2, -6, -4, -4, 0}));
        System.out.println(maxProduct(new int[]{-4, -3, -2, -5}));
    }

    public static int maxProduct(int[] nums) {
        int globalMax = nums[0];
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int lastMax = maxSoFar;
            maxSoFar = Math.max(Math.max(maxSoFar * nums[i], minSoFar * nums[i]), nums[i]);
            minSoFar = Math.min(Math.min(lastMax * nums[i], minSoFar * nums[i]), nums[i]);
            globalMax = Math.max(globalMax, maxSoFar);
        }
        return globalMax;
    }
}
