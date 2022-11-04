package LeetCode;

public class FindPivotIndex {
    public static void main(String[] args) {
        System.out.println(pivotIndex(new int[]{1, 7, 3, 6, 5, 6}));
        System.out.println(pivotIndex(new int[]{1, 2, 3}));
        System.out.println(pivotIndex(new int[]{2, 1, -1}));
        System.out.println(pivotIndex(new int[]{1, -1, 2}));
    }

    public static int pivotIndex(int[] nums) {
        int total = nums[0];
        for (int i = 1; i < nums.length; i++) {
            total += nums[i];
        }

        int tillNow = 0;
        for (int i = 0; i < nums.length; i++) {
            if (tillNow == (total - nums[i] - tillNow))
                return i;
            else
                tillNow += nums[i];
        }

        if (tillNow == 0)
            return nums.length - 1;

        return -1;
    }
}
