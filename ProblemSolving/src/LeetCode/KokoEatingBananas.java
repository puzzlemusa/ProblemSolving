package LeetCode;


public class KokoEatingBananas {

    public static void main(String[] args) {
        System.out.println(minEatingSpeed(new int[]{3, 6, 7, 11}, 8));
        System.out.println(minEatingSpeed(new int[]{30, 11, 23, 4, 20}, 5));
        System.out.println(minEatingSpeed(new int[]{30, 11, 23, 4, 20}, 6));
        System.out.println(minEatingSpeed(new int[]{312884470}, 312884469));
    }

    public static int minEatingSpeed(int[] piles, int h) {
        int right = 0;
        int left = 1;
        for (int pile : piles) {
            right = Math.max(right, pile);
        }

        while (left < right) {
            int k = left + (right - left) / 2;
            if (canEatAll(piles, k, h)) {
                right = k;
            } else {
                left = k + 1;
            }
        }

        return left;
    }

    private static boolean canEatAll(int[] piles, int k, int h) {
        int hour = 0;
        for (int pile : piles) {
            hour += pile / k;
            if (pile % k != 0) {
                hour++;
            }
        }

        return h >= hour;
    }
}
