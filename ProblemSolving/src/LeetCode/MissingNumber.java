package LeetCode;


public class MissingNumber {

    public static void main(String[] args) {
        System.out.println(missingNumber(new int[]{0}));
        System.out.println(missingNumber(new int[]{3, 0, 1}));
        System.out.println(missingNumber(new int[]{0, 1}));
        System.out.println(missingNumber(new int[]{9, 6, 4, 2, 3, 5, 7, 0, 1}));
    }

    public static int missingNumber(int[] nums) {
        int tot = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            tot += nums[i];
        }

        return ((n * (n + 1)) / 2) - tot;
    }
}
