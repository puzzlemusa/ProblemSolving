package LeetCode;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class DistributeElementsIntoTwoArraysI {

    public static void main(String[] args) {
        System.out.println(Arrays.toString(resultArray(new int[]{2, 1, 3})));
        System.out.println(Arrays.toString(resultArray(new int[]{5, 4, 3, 8})));
    }

    // Time complexity O(n), space complexity O(n)
    public static int[] resultArray(int[] nums) {
        List<Integer> list1 = new LinkedList<>();
        List<Integer> list2 = new LinkedList<>();

        list1.add(nums[0]);
        list2.add(nums[1]);

        for (int i = 2; i < nums.length; i++) {
            if (list1.get(list1.size() - 1) > list2.get(list2.size() - 1)) {
                list1.add(nums[i]);
            } else {
                list2.add(nums[i]);
            }
        }

        list1.addAll(list2);
        return list1.stream().mapToInt(Integer::intValue).toArray();
    }
}
