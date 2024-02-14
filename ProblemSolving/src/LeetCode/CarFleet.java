package LeetCode;


import java.util.Collections;
import java.util.Map;
import java.util.TreeMap;

public class CarFleet {

    public static void main(String[] args) {
        System.out.println(carFleet(12, new int[]{10, 8, 0, 5, 3}, new int[]{2, 4, 1, 1, 3}));
        System.out.println(carFleet(10, new int[]{3}, new int[]{3}));
        System.out.println(carFleet(100, new int[]{0, 2, 4}, new int[]{4, 2, 1}));
    }

    // Time complexity: O(nlogn), Space complexity: O(n)
    public static int carFleet(int target, int[] position, int[] speed) {
        Map<Integer, Double> mp = new TreeMap<>(Collections.reverseOrder());

        for (int i = 0; i < position.length; i++) {
            mp.put(position[i], (double) (target - position[i]) / speed[i]);
        }

        int fleet = 0;
        double curr = 0;
        for (double time : mp.values()) {
            if (time > curr) {
                curr = time;
                fleet++;
            }
        }
        return fleet;
    }
}
