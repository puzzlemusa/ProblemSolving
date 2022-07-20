package LeetCode;

import java.util.*;

public class ThreeSum {
    public static void main(String[] args) {
        System.out.println(threeSum(new int[]{0, 0, 0, 0}));
        System.out.println(threeSum(new int[]{-1, 0, 1, 2, -1, -4}));
        System.out.println(threeSum(new int[]{0, 1, 1}));
        System.out.println(threeSum(new int[]{0, 0, 0}));
        System.out.println("......................");
        System.out.println(threeSumWithoutSet(new int[]{0, 0, 0, 0}));
        System.out.println(threeSumWithoutSet(new int[]{-1, 0, 1, 2, -1, -4}));
        System.out.println(threeSumWithoutSet(new int[]{0, 1, 1}));
        System.out.println(threeSumWithoutSet(new int[]{0, 0, 0}));
    }

    public static List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);

        Set<List<Integer>> result = new HashSet<>();
        use2Sum(0, nums, result);
        for (int i = 1; i < nums.length - 2; i++) {
            if (nums[i] != nums[i - 1]) {
                use2Sum(i, nums, result);
            }
        }

        return new ArrayList<>(result);
    }

    public static void use2Sum(int index, int[] nums, Set<List<Integer>> result) {
        HashSet<Integer> store = new HashSet<>();
        for (int i = index + 1; i < nums.length; i++) {
            int valueNeeded = -(nums[i] + nums[index]);
            if (store.contains(valueNeeded)) {
                result.add(List.of(valueNeeded, nums[i], nums[index]));
            } else {
                store.add(nums[i]);
            }
        }
    }

    public static List<List<Integer>> threeSumWithoutSet(int[] nums) {
        Arrays.sort(nums);

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < nums.length - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int start = i + 1;
                int end = nums.length - 1;
                int goal = -nums[i];

                while (start < end) {
                    if (goal == (nums[start] + nums[end])) {
                        result.add(Arrays.asList(nums[i], nums[start], nums[end]));
                        start++;
                        end--;
                        while (start < end && nums[start] == nums[start - 1]) {
                            start++;
                        }
                        while (start < end && nums[end] == nums[i + 1]) {
                            end--;
                        }
                    } else if (goal > (nums[start] + nums[end])) {
                        start++;
                    } else {
                        end--;
                    }
                }
            }
        }
        return new ArrayList<>(result);
    }
}
