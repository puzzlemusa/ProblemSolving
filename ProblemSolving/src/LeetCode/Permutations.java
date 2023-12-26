package LeetCode;

import java.util.ArrayList;
import java.util.List;

public class Permutations {
    public static void main(String[] args) {
        System.out.println(permute(new int[]{1, 2, 3}));
        System.out.println(permute(new int[]{1}));
        System.out.println(permute(new int[]{1, 2}));
    }

    // Complexity O(n!)
    public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList();

        compute(nums, 0, result);

        return result;
    }

    public static void compute(int[] nums, int start, List<List<Integer>> result) {
        if (start == nums.length - 1) {
            List<Integer> list = new ArrayList();
            for (int i = 0; i < nums.length; i++) {
                list.add(nums[i]);
            }
            result.add(list);
        } else {
            for (int i = start; i < nums.length; i++) {
                swap(nums, i, start);
                compute(nums, start + 1, result);
                swap(nums, i, start);
            }
        }
    }

    public static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
