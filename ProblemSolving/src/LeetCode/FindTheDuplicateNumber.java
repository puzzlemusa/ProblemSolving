package LeetCode;


public class FindTheDuplicateNumber {

    public static void main(String[] args) {
        System.out.println(findDuplicate(new int[]{1, 3, 4, 2, 2}));
        System.out.println(findDuplicate(new int[]{3, 1, 3, 4, 2}));
    }

    // O(n)
    public static int findDuplicate(int[] nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

    // nlog(n)
    public static int findDuplicate1(int[] nums) {
        int low = 1;
        int high = nums.length - 1;
        int duplicate = -1;

        while (low <= high) {
            int cur = (low + high) / 2;

            int count = 0;
            for (int num : nums) {
                if (num <= cur)
                    count++;
            }

            if (count > cur) {
                duplicate = cur;
                high = cur - 1;
            } else {
                low = cur + 1;
            }
        }
        return duplicate;
    }
}
