package LeetCode;


import java.util.ArrayList;
import java.util.List;

public class Subsets {

    public static void main(String[] args) {
        System.out.println(subsets(new int[]{1, 2, 3}));
        System.out.println(subsets1(new int[]{1, 2, 3}));
        System.out.println(subsets2(new int[]{1, 2, 3}));
    }

    public static List<List<Integer>> subsets1(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i <= nums.length; i++) {
            find(0, i, nums, result, new ArrayList<>());
        }
        return result;
    }

    private static void find(int start, int k, int[] nums, List<List<Integer>> result, List<Integer> curr) {
        if (curr.size() == k) {
            result.add(new ArrayList<>(curr));
        } else {
            for (int i = start; i < nums.length; i++) {
                curr.add(nums[i]);
                find(i + 1, k, nums, result, curr);
                curr.remove(curr.size() - 1);
            }
        }
    }

    public static List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> output = new ArrayList<>();
        int n = nums.length;

        for (int i = (int) Math.pow(2, n); i < (int) Math.pow(2, n + 1); ++i) {
            // generate bitmask, from 0..00 to 1..11
            String bitmask = Integer.toBinaryString(i).substring(1);

            // append subset corresponding to that bitmask
            List<Integer> curr = new ArrayList<>();
            for (int j = 0; j < n; ++j) {
                if (bitmask.charAt(j) == '1') curr.add(nums[j]);
            }
            output.add(curr);
        }
        return output;
    }

    // Complexity O(2^n)
    public static List<List<Integer>> subsets2(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        find2(0, nums, result, curr);
        return result;
    }

    private static void find2(int start, int[] nums, List<List<Integer>> result, List<Integer> curr) {
        if (start >= nums.length) {
            result.add(new ArrayList<>(curr));
        } else {
            curr.add(nums[start]);
            find2(start + 1, nums, result, curr);
            curr.remove(curr.size() - 1);
            find2(start + 1, nums, result, curr);
        }
    }
}
