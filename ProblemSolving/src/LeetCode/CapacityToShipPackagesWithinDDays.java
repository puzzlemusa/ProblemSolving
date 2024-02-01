package LeetCode;


public class CapacityToShipPackagesWithinDDays {

    public static void main(String[] args) {
        System.out.println(shipWithinDays(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5));
        System.out.println(shipWithinDays(new int[]{3, 2, 2, 4, 1, 4}, 3));
        System.out.println(shipWithinDays(new int[]{1, 2, 3, 1, 1}, 4));
    }

    // Time complexity: O(nlogm), space complexity: O(1). n is the length of weights, m is the sum of weights - max(wights).
    public static int shipWithinDays(int[] weights, int days) {
        int left = 0;
        int right = 0;
        for (int weight : weights) {
            left = Math.max(left, weight);
            right += weight;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canHold(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;

    }

    private static boolean canHold(int[] weights, int days, int capacity) {
        int daysNeeded = 1;
        int weightSoFar = 0;
        for (int weight : weights) {
            if (weightSoFar + weight > capacity) {
                daysNeeded++;
                weightSoFar = 0;
            }
            weightSoFar += weight;
        }

        return daysNeeded <= days;
    }
}
