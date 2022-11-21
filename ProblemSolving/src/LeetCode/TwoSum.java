package LeetCode;


import java.util.*;

public class TwoSum {

    public static void main(String[] args) {
        System.out.println(twoSum(new int[]{2, 7, 11, 15}, 9));
        System.out.println(twoSum(new int[]{3, 2, 4}, 6));
        System.out.println(twoSum(new int[]{3, 3}, 6));
    }

    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mem = new HashMap<>();
        mem.put(nums[0], 0);
        for (int i = 1; i < nums.length; i++) {
            if (mem.containsKey(target - nums[i])) {
                return new int[]{mem.get(target - nums[i]), i};
            } else {
                mem.put(nums[i], i);
            }
        }
        return null;
    }
}
