package AlgorithmPractice;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CyclicSort {

    public static void cyclicSort(int[] nums) {
        int i = 0;
        while (i < nums.length) {
            int j = nums[i] - 1;
            if (nums[i] != nums[j])
                swap(nums, i, j);
            else
                i++;
        }
    }

    public static int findMissingNumber(int[] nums) {
        int i = 0;
        while (i < nums.length) {
            if (nums[i] < nums.length && nums[i] != nums[nums[i]])
                swap(nums, i, nums[i]);
            else
                i++;
        }

        for (i = 0; i < nums.length; i++)
            if (nums[i] != i)
                return i;

        return nums.length;
    }

    public static int findDuplicateNumber(int[] nums) {
        int i = 0;
        while (i < nums.length) {
            if (nums[i] != nums[nums[i] - 1])
                swap(nums, i, nums[i] - 1);
            else
                i++;
        }

        for (i = 0; i < nums.length; i++)
            if (nums[i] != i + 1)
                return nums[i];

        return -1;
    }

    public static List<Integer> findAllMissingNumbers(int[] nums) {
        int i = 0;
        while (i < nums.length) {
            if (nums[i] != nums[nums[i] - 1])
                swap(nums, i, nums[i] - 1);
            else
                i++;
        }

        List<Integer> missingNumbers = new ArrayList<>();
        for (i = 0; i < nums.length; i++)
            if (nums[i] != i + 1)
                missingNumbers.add(i + 1);

        return missingNumbers;
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] a = new int[]{3, 1, 5, 4, 2};
        cyclicSort(a);
        System.out.println(Arrays.toString(a));
        System.out.println(findDuplicateNumber(new int[]{4, 2, 3, 5, 5, 1}));
        System.out.println(findMissingNumber(new int[]{4, 0, 3, 1}));
        System.out.println(findAllMissingNumbers(new int[]{2, 3, 1, 8, 2, 3, 5, 1}));
    }
}
