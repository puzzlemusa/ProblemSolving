package AlgorithmPractice;

import java.util.Arrays;

public class MergeSort {

    public static void main(String[] args) {
        int[] a = new int[]{4, 2, 6, 1, 5, 3};
        mergeSort(a, 6);
        System.out.println(Arrays.toString(a));
    }

    // Time complexity: O(nlogn), space complexity: O(n)
    public static void mergeSort(int[] nums, int size) {
        if (size < 2) {
            return;
        }

        int mid = size / 2;
        int[] leftSide = new int[mid];
        int[] rightSide = new int[size - mid];
        for (int i = 0; i < mid; i++) {
            leftSide[i] = nums[i];
        }
        for (int i = mid; i < size; i++) {
            rightSide[i - mid] = nums[i];
        }
        mergeSort(leftSide, mid);
        mergeSort(rightSide, size - mid);
        merge(nums, leftSide, rightSide, mid, size - mid);
    }

    private static void merge(int[] nums, int[] leftSide, int[] rightSide, int sizeLeft, int sizeRight) {
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < sizeLeft && j < sizeRight) {
            if (leftSide[i] <= rightSide[j]) {
                nums[k++] = leftSide[i++];
            } else {
                nums[k++] = rightSide[j++];
            }
        }
        while (i<sizeLeft){
            nums[k++] = leftSide[i++];
        }
        while (j<sizeRight){
            nums[k++] = rightSide[j++];
        }
    }
}
