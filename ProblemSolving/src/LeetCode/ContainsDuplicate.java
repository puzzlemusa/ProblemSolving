package LeetCode;

import java.util.HashSet;

public class ContainsDuplicate {

    public static void main(String[] args) {
        System.out.println(containsDuplicate(new int[]{1, 2, 3, 1}));
        System.out.println(containsDuplicate(new int[]{1, 2, 3, 4}));
        System.out.println(containsDuplicate(new int[]{1}));

        System.out.println(containsDuplicate1(new int[]{1, 2, 3, 1}));
        System.out.println(containsDuplicate1(new int[]{1, 2, 3, 4}));
        System.out.println(containsDuplicate1(new int[]{1}));
    }

    // Wont work for big number.
    public static boolean containsDuplicate(int[] nums) {
        int xd = 0;
        int temp;
        for (int i = 0; i < nums.length; i++) {
            temp = 1 << nums[i];
            if((temp & xd) != 0)
                return true;
            else
                xd|=temp;
        }

        return false;
    }

    public static boolean containsDuplicate1(int[] nums) {
        HashSet<Integer> hashSet = new HashSet();
        for (int num : nums) {
            if (hashSet.contains(num))
                return true;
            else
                hashSet.add(num);
        }

        return false;
    }
}
