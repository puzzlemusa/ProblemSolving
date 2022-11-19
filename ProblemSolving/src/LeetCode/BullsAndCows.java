package LeetCode;


import java.util.HashMap;
import java.util.Map;

public class BullsAndCows {

    public static void main(String[] args) {
        System.out.println(getHint("1807", "7810"));
        System.out.println(getHint("1123", "0111"));
        System.out.println(getHint("1123", "1123"));
        System.out.println(getHint("1123", "9999"));
        System.out.println(getHint("11", "10"));
        System.out.println("---------------------------------");
        System.out.println(getHint1("1807", "7810"));
        System.out.println(getHint1("1123", "0111"));
        System.out.println(getHint1("1123", "1123"));
        System.out.println(getHint1("1123", "9999"));
        System.out.println(getHint1("11", "10"));
    }

    public static String getHint(String secret, String guess) {
        Map<Character, Integer> digitToFreq = new HashMap<>();
        int bulls = 0;
        char[] gg = new char[guess.length()];
        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) == guess.charAt(i)) {
                bulls++;
                gg[i] = 'X';
            } else {
                gg[i] = guess.charAt(i);
                digitToFreq.put(secret.charAt(i), digitToFreq.getOrDefault(secret.charAt(i), 0) + 1);
            }
        }
        int cows = 0;
        for (int i = 0; i < guess.length(); i++) {
            Integer freq = digitToFreq.get(gg[i]);
            if (freq != null) {
                cows++;
                if (freq > 1) {
                    digitToFreq.put(gg[i], freq - 1);
                } else {
                    digitToFreq.remove(gg[i]);
                }
            }
        }
        return bulls + "A" + cows + "B";
    }

    public static String getHint1(String secret, String guess) {
        int bulls = 0;
        int cows = 0;
        int[] numbers = new int[10];
        for (int i = 0; i < secret.length(); i++) {
            int s = Character.getNumericValue(secret.charAt(i));
            int g = Character.getNumericValue(guess.charAt(i));
            if (s == g) bulls++;
            else {
                if (numbers[s] < 0) cows++;
                if (numbers[g] > 0) cows++;
                numbers[s]++;
                numbers[g]--;
            }
        }
        return bulls + "A" + cows + "B";
    }
}
