package LeetCode;


public class FindMinimumInRotatedSortedArray {

    public static void main(String[] args) {
        System.out.println(findMin(new int[]{3, 4, 5, 1, 2}));
        System.out.println(findMin(new int[]{4, 5, 6, 7, 0, 1, 2}));
        System.out.println(findMin(new int[]{11, 13, 15, 17}));
        System.out.println(findMin(new int[]{4, 5, 6, 7, 0, 1, 2}));
        System.out.println(findMin(new int[]{3, 4, 5, 6, 7, 1, 2}));
        System.out.println(findMin(new int[]{7, 1, 2, 3, 4, 5, 6}));
        System.out.println(findMin(new int[]{5, 6, 7, 1, 2, 3, 4}));
        System.out.println(findMin(new int[]{1}));
        System.out.println(findMin(new int[]{1, 2}));
        System.out.println(findMin(new int[]{2, 1}));
        System.out.println(findMin(new int[]{5, 1, 2, 3, 4}));
    }

    public static int findMin(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[left] < nums[right]) {
                return nums[left];
            }

            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
}
