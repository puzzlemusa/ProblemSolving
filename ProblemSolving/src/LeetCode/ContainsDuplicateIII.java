package LeetCode;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeSet;

public class ContainsDuplicateIII {
    public static void main(String[] args) {
        System.out.println(containsNearbyAlmostDuplicate1(new int[]{1, 2, 3, 1}, 3, 0));
        System.out.println(containsNearbyAlmostDuplicate1(new int[]{1, 5, 9, 1, 5, 9}, 2, 3));
        System.out.println(containsNearbyAlmostDuplicate1(new int[]{-3, 3}, 2, 4));
    }

    // Time complexity O(nlogk), space complexity O(k)
    public static boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        TreeSet<Integer> uniqueNums = new TreeSet<>();
        for (int i = 0; i < nums.length; i++) {
            Integer floor = uniqueNums.floor(nums[i]);
            Integer ceiling = uniqueNums.ceiling(nums[i]);

            if (floor != null && nums[i] - floor <= valueDiff) {
                return true;
            }
            if (ceiling != null && ceiling - nums[i] <= valueDiff) {
                return true;
            }

            uniqueNums.add(nums[i]);
            if(uniqueNums.size() > indexDiff) {
                uniqueNums.remove(nums[i - indexDiff]);
            }
        }

        return false;
    }

    public static boolean containsNearbyAlmostDuplicate1(int[] nums, int indexDiff, int valueDiff) {
        Map<Integer, Integer> bucketToNum = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int bucket = nums[i] / (valueDiff + 1);
            // For negative numbers, we need to decrement bucket by 1
            // to ensure floor division.
            // For example, -1/2 = 0 but -1 should be put in Bucket[-1].
            // Therefore, decrement by 1.
            if(nums[i] < 0) --bucket;
            if (bucketToNum.containsKey(bucket)) {
                return true;
            }
            if (bucketToNum.containsKey(bucket - 1) && Math.abs(nums[i] - bucketToNum.get(bucket - 1)) <= valueDiff) {
                return true;
            }
            if (bucketToNum.containsKey(bucket + 1) && Math.abs(nums[i] - bucketToNum.get(bucket + 1)) <= valueDiff) {
                return true;
            }

            bucketToNum.put(bucket, nums[i]);
            if (bucketToNum.size() > indexDiff) {
                bucketToNum.remove(nums[i - indexDiff] / (valueDiff + 1));
            }
        }

        return false;
    }
}
