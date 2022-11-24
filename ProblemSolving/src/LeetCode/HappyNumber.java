package LeetCode;

import java.util.HashSet;
import java.util.Set;

public class HappyNumber {

    public static void main(String[] args) {
        System.out.println(isHappy(9999));
        System.out.println(isHappy(19));
        System.out.println(isHappy(18));
        System.out.println(isHappy(2));

        System.out.println("------------------");

        //System.out.println(isHappy1(9999));
        System.out.println(isHappy1(19));
        System.out.println(isHappy1(18));
        System.out.println(isHappy1(2));
    }

    public static boolean isHappy(int n) {
        Set<Integer> seen = new HashSet<>();
        while (n != 1 && !seen.contains(n)) {
            seen.add(n);
            n = getItem(n);
        }
        return n == 1;

    }

    // Floyd cycle detection
    public static boolean isHappy1(int n) {
        int slow = getItem(n);
        int fast = getItem(slow);
        while (slow != fast) {
            slow = getItem(slow);
            fast = getItem(fast);
            fast = getItem(fast);
        }
        return slow == 1;
    }

    private static int getItem(int n) {
        int total = 0;
        while (n != 0) {
            int mod = n % 10;
            n = n / 10;
            total += (mod * mod);
        }
        return total;
    }
}
