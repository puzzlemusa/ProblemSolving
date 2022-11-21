package LeetCode;


import java.util.Random;

public class KthLargestElementInAnArray {

    public static void main(String[] args) {
        //System.out.println(findKthLargest(new int[]{3, 2, 1, 5, 6, 4}, 2));
        System.out.println(findKthLargest(new int[]{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4));
    }

    public static int findKthLargest(int[] nums, int k) {
        return quickSelect(nums, 0, nums.length - 1, k);
    }

    public static int quickSelect(int[] nums, int low, int high, int k) {
        int pivot = low;
        for (int i = low; i < high; i++) {
            if (nums[i] <= nums[high]) {
                swap(nums, pivot, i);
                pivot++;
            }
        }
        swap(nums, pivot, high);

        int highNumberBiggerThanPivotFromHigh = high - pivot + 1;

        if (highNumberBiggerThanPivotFromHigh == k)
            return nums[pivot];
        if (highNumberBiggerThanPivotFromHigh > k)
            return quickSelect(nums, pivot + 1, high, k);
        else
            return quickSelect(nums, low, pivot - 1, k - highNumberBiggerThanPivotFromHigh);
    }

    private static void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

    public static int quickSelect1(int[] nums, int low, int high, int k) {
        int random = new Random().nextInt(high - low + 1) + low;
        swap(nums, random, low);
        int pivot = low;
        for (int i = low; i < high; i++) {
            if (nums[i] <= nums[high]) {
                swap(nums, pivot, i);
                pivot++;
            }
        }
        swap(nums, pivot, high);

        int highNumberBiggerThanPivotFromHigh = high - pivot + 1;

        if (highNumberBiggerThanPivotFromHigh == k)
            return nums[pivot];
        if (highNumberBiggerThanPivotFromHigh > k)
            return quickSelect(nums, pivot + 1, high, k);
        else
            return quickSelect(nums, low, pivot - 1, k - highNumberBiggerThanPivotFromHigh);
    }
}
