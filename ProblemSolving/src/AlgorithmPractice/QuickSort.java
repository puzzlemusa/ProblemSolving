package AlgorithmPractice;

import java.util.Arrays;

public class QuickSort {

    public static void main(String[] args) {
        int[] a = new int[]{4, 2, 6, 1, 5, 3};
        quickSort(a, 0, a.length - 1);
        System.out.println(Arrays.toString(a));
    }

    public static void quickSort(int[] nums, int low, int high) {
        if (low < high) {
            int pivot = partition(nums, low, high);
            quickSort(nums, low, pivot - 1);
            quickSort(nums, pivot, high);
        }
    }

    private static int partition(int[] nums, int left, int right) {
        int pivot = nums[right];
        for (int i = left; i <= right; i++) {
            if (nums[i] < pivot) {
                swap(nums, i, left);
                left++;
            }
        }
        swap(nums, left, right);
        return left;
    }

    private static void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
}
