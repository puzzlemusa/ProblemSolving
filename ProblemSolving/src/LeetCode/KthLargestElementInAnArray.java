package LeetCode;


import java.util.Random;

public class KthLargestElementInAnArray {

    public static void main(String[] args) {
        System.out.println(findKthLargest(new int[]{3, 2, 1, 5, 6, 4}, 2));
        System.out.println(findKthLargest(new int[]{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4));
    }

    // Time complexity: O(n) in average case, O(n^2) in worst case
    // Space complexity: O(lon(n)) in average case, O(n) in worst case
    public static int findKthLargest(int[] nums, int k) {
        return quickSelect(nums, 0, nums.length - 1, k - 1);
    }

    public static int quickSelect(int[] nums, int low, int high, int k) {
        int pivot = partition(nums, low, high);
        if (pivot == k)
            return nums[pivot];
        if (pivot < k)
            return quickSelect(nums, pivot + 1, high, k);
        else
            return quickSelect(nums, low, pivot - 1, k);
    }

    public static int partition(int[] nums, int low, int high) {
        int pivot = high;
        for (int i = low; i < high; i++) {
            if (nums[i] > nums[pivot]) {
                swap(nums, low, i);
                low++;
            }
        }
        swap(nums, pivot, low);
        return low;
    }

    private static void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

    public static int partition1(int[] nums, int low, int high) {
        int random = new Random().nextInt(high - low + 1) + low;
        swap(nums, random, high);
        int pivot = high;
        for (int i = low; i < high; i++) {
            if (nums[i] > nums[pivot]) {
                swap(nums, low, i);
                low++;
            }
        }
        swap(nums, pivot, low);
        return low;
    }

}
