package LeetCode;


import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class LongestConsecutiveSequence {

    public static void main(String[] args) {
        System.out.println(longestConsecutive(new int[]{100, 4, 200, 1, 3, 2}));
        System.out.println(longestConsecutive(new int[]{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}));
        System.out.println(longestConsecutive(new int[]{}));
        System.out.println(longestConsecutive(new int[]{1}));
        System.out.println(longestConsecutive(new int[]{1, 2}));
        System.out.println(longestConsecutive(new int[]{1, 3}));
        System.out.println(longestConsecutive(new int[]{1, 1}));
        System.out.println(longestConsecutive(new int[]{1, 2, 0, 1}));
    }

    public static int longestConsecutive1(int[] nums) {
        Arrays.sort(nums);

        if (nums.length == 1 || nums.length == 0)
            return nums.length;

        int res = 1;
        int curr = 1;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] + 1 == nums[i + 1]) {
                curr++;
                res = Math.max(res, curr);
            } else if (nums[i] != nums[i + 1]) {
                curr = 1;
            }
        }
        return res;
    }

    //Better O(n)
    public static int longestConsecutive(int[] nums) {
        Set<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
        }

        int mx = 0;
        for (int num : numSet) {
            if (!numSet.contains(num - 1)) {
                int currNum = num;
                int currLen = 1;
                while (numSet.contains(currNum + 1)) {
                    currNum++;
                    currLen++;
                }
                mx = Math.max(mx, currLen);
            }
            if (mx > nums.length / 2) {
                break;
            }
        }

        return mx;
    }
}
