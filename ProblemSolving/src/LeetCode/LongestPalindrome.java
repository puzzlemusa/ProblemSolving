package LeetCode;

import java.util.HashMap;
import java.util.Map;

public class LongestPalindrome {
    public static void main(String[] args) {
        System.out.println(longestPalindrome("abccccdd"));
        System.out.println(longestPalindrome("a"));
    }

    public static int longestPalindrome(String s) {
        Map<Character, Integer> charToInt = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            charToInt.merge(s.charAt(i), 1, Integer::sum);
        }

        int maxPal = 0;
        boolean hasOdd = false;
        for (Integer frequency : charToInt.values()) {
            if (frequency % 2 == 0)
                maxPal += frequency;
            else {
                hasOdd = true;
                maxPal+= (frequency-1);
            }
        }

        return hasOdd ? maxPal +1 : maxPal;
    }
}
