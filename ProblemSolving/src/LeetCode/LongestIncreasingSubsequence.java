package LeetCode;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LongestIncreasingSubsequence {
    public static void main(String[] args) {
        System.out.println(lengthOfLIS2(new int[]{10, 9, 2, 5, 3, 7, 101, 18}));
        System.out.println(lengthOfLIS2(new int[]{0, 1, 0, 3, 2, 3}));
        System.out.println(lengthOfLIS2(new int[]{7, 7, 7, 7, 7, 7, 7}));
        System.out.println(lengthOfLIS2(new int[]{3, 2, 1}));
        System.out.println(lengthOfLIS2(new int[]{4, 10, 4, 3, 8, 9}));
    }

    public static int lengthOfLIS(int[] nums) {
        return findLIS(nums, 0, Integer.MIN_VALUE);
    }

    // Time complexity: O(2^n), Space complexity: O(n)
    private static int findLIS(int[] nums, int index, int prev) {
        if (index == nums.length) {
            return 0;
        }

        int skipCurr = findLIS(nums, index + 1, prev);
        int temp = 0;
        if (nums[index] > prev) {
            temp = findLIS(nums, index + 1, nums[index]) + 1;
        }

        return Math.max(skipCurr, temp);
    }

    // Time complexity: O(n^2), Space complexity: O(n)
    public static int lengthOfLIS1(int[] nums) {
        int[] mem = new int[nums.length];
        Arrays.fill(mem, 1);
        int max = 1;
        for (int i = 0; i < mem.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    mem[i] = Math.max(mem[i], mem[j] + 1);
                    max = Math.max(max, mem[i]);
                }
            }
        }

        return max;
    }

    // Time complexity: O(nlogn), Space complexity: O(n)
    public static int lengthOfLIS2(int[] nums) {
        List<Integer> list = new ArrayList<>();
        list.add(nums[0]);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > list.get(list.size() - 1)) {
                list.add(nums[i]);
            } else {
                int left = 0;
                int right = list.size() - 1;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (nums[i] > list.get(mid)) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                list.set(left, nums[i]);
            }
        }

        return list.size();
    }
}
