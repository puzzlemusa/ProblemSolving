package LeetCode;


import java.util.Arrays;

public class NextPermutation {

    public static void main(String[] args) {
        int[] nums1 = new int[]{1, 2, 3};
        nextPermutation(nums1);
        System.out.println(Arrays.toString(nums1));

        int[] nums2 = new int[]{3, 2, 1};
        nextPermutation(nums2);
        System.out.println(Arrays.toString(nums2));

        int[] nums3 = new int[]{1, 1, 5};
        nextPermutation(nums3);
        System.out.println(Arrays.toString(nums3));

        int[] nums4 = new int[]{1, 3, 2};
        nextPermutation(nums4);
        System.out.println(Arrays.toString(nums4));
    }

    // Time complexity: O(nlong(n)), space complexity: O(n).
    public static void nextPermutation(int[] nums) {
        int breakPoint = -1;
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakPoint = i;
                break;
            }
        }
        if (breakPoint == -1) {
            reverse(nums, 0, nums.length - 1);
        } else {
            for (int i = nums.length - 1; i >= 0; i--) {
                if (nums[i] > nums[breakPoint]) {
                    swap(nums, breakPoint, i);
                    reverse(nums, breakPoint + 1, nums.length - 1);
                    break;
                }
            }
        }
    }

    private static void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

    private static void reverse(int[] nums, int start, int end) {
        while (start <= end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }
}
