package LeetCode;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SubsetsII {

    public static void main(String[] args) {
        System.out.println(subsetsWithDup(new int[]{1, 2, 2}));
    }

    // Complexity O(n*2^n)
    public static List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        find(0, nums, result, curr);
        return result;
    }

    private static void find(int idx, int[] nums, List<List<Integer>> result, List<Integer> curr) {
        result.add(new ArrayList<>(curr));
        for (int i = idx; i < nums.length; i++) {
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
            curr.add(nums[i]);
            find(i + 1, nums, result, curr);
            curr.remove(curr.size() - 1);
        }
    }
}
