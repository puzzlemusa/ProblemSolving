package LeetCode;


public class JumpGame {

    public static void main(String[] args) {
        System.out.println(canJump(new int[]{2, 3, 1, 1, 4}));
        System.out.println(canJump(new int[]{3, 2, 1, 0, 4}));
        System.out.println(canJump(new int[]{0}));
        System.out.println(canJump(new int[]{10, 0}));
    }

    public static boolean canJump(int[] nums) {
        boolean[] canReach = new boolean[nums.length];
        canReach[nums.length - 1] = true;

        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] + i >= nums.length - 1) {
                canReach[i] = true;
                continue;
            }
            for (int j = nums[i]; j > 0; j--) {
                if (canReach[i + j]) {
                    canReach[i] = true;
                    break;
                }
            }
        }

        return canReach[0];
    }

    public static boolean canJump1(int[] nums) {
        int maxJumpedLength = 0;

        for (int i = 0; i <= maxJumpedLength; i++) {
            maxJumpedLength = Math.max(maxJumpedLength, i + nums[i]);
            if (maxJumpedLength >= nums.length - 1) {
                return true;
            }
        }
        return false;
    }
}
