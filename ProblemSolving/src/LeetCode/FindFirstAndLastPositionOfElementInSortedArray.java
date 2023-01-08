package LeetCode;


import java.util.Arrays;

public class FindFirstAndLastPositionOfElementInSortedArray {

    public static void main(String[] args) {
        System.out.println(Arrays.toString(searchRange(new int[]{5, 5, 8, 8, 8, 10, 10}, 8)));
        System.out.println(Arrays.toString(searchRange(new int[]{5, 5, 8, 8, 8, 10, 10}, 10)));
        System.out.println(Arrays.toString(searchRange(new int[]{5, 5, 8, 8, 8, 10, 10}, 5)));
        System.out.println(Arrays.toString(searchRange(new int[]{5, 5, 8, 8, 8, 10, 10}, 6)));
        System.out.println(Arrays.toString(searchRange(new int[]{5, 5, 8, 8, 8, 10, 10}, 4)));
        System.out.println(Arrays.toString(searchRange(new int[]{5, 5, 8, 8, 8, 10, 10}, 11)));
        System.out.println(Arrays.toString(searchRange(new int[]{5, 5, 8, 8, 9, 10, 10}, 9)));
        System.out.println(Arrays.toString(searchRange(new int[]{5, 6}, 5)));
        System.out.println(Arrays.toString(searchRange(new int[]{5, 6}, 6)));
        System.out.println(Arrays.toString(searchRange(new int[]{5, 7, 7, 8, 8, 10}, 8)));
    }

    public static int[] searchRange(int[] nums, int target) {
        int lowerBound = lowerBound(nums, target);
        if (nums.length == 0 || nums[lowerBound] != target) {
            return new int[]{-1, -1};
        }
        int upperBound = upperBound(nums, target);

        return nums[upperBound] == target
                ? new int[]{lowerBound, upperBound}
                : new int[]{lowerBound, upperBound - 1};
    }

    private static int upperBound(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (target >= nums[mid])
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }

    private static int lowerBound(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (target <= nums[mid])
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
}
