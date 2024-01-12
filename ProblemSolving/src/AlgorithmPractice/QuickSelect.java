package AlgorithmPractice;


import java.util.Arrays;

public class QuickSelect {
    public static void main(String[] args) {
        System.out.println(Arrays.toString(topKElement(new int[]{3, 0, 1, 0}, 1)));
        System.out.println(Arrays.toString(topKElement(new int[]{1, 1, 1, 2, 2, 3}, 2)));
        System.out.println(Arrays.toString(topKElement(new int[]{1, 1, 1, 2, 2, 3}, 3)));
        System.out.println(Arrays.toString(topKElement(new int[]{1}, 1)));
    }

    // AVG Complexity O(n), WORST Complexity n^2 when bad pivot chosen.
    // Memory avg O(logn), worst O(n)
    public static int[] topKElement(int[] nums, int k) {
        quickSelect(nums, 0, nums.length - 1, nums.length - k);
        return Arrays.copyOfRange(nums, nums.length - k, nums.length);
    }

    private static void quickSelect(int[] nums, int left, int right, int k) {
        if (left < right) {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == k) {
            } else if (pivotIndex < k) {
                quickSelect(nums, pivotIndex + 1, right, k);
            } else {
                quickSelect(nums, left, pivotIndex - 1, k);
            }
        }
    }

    private static int partition(int[] nums, int left, int right) {
        int pivot = nums[right];
        for (int i = left; i <= right; i++) {
            if (nums[i] < pivot) {
                swap(nums, left, i);
                left++;
            }
        }

        swap(nums, left, right);

        return left;
    }

    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}