package LeetCode;


import java.util.HashMap;
import java.util.Map;

public class MaximumWindowSubstring {

    public static void main(String[] args) {
        System.out.println(minWindow("ADOBECODEBANC", "ABC"));
        System.out.println(minWindow("a", "a"));
        System.out.println(minWindow("a", "aa"));
        System.out.println(minWindow("aa", "aa"));
        System.out.println(minWindow("bba", "ba"));
    }

    // Time: O(n), space: O(n)
    public static String minWindow(String s, String t) {
        Map<Character, Integer> freq = new HashMap<>();
        for (int i = 0; i < t.length(); i++) {
            Character ch = t.charAt(i);
            freq.put(ch, freq.getOrDefault(ch, 0) + 1);
        }

        int remainingMatch = freq.size();
        int left = 0;
        int start = 0;
        int minLength = s.length() + 1;
        for (int right = 0; right < s.length(); right++) {
            Character chRight = s.charAt(right);
            Integer f = freq.get(chRight);
            if (f != null) {
                f--;
                freq.put(chRight, f);
                if (f == 0) {
                    remainingMatch--;
                }
            }

            while (remainingMatch == 0) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }
                Character chLeft = s.charAt(left++);
                if (freq.containsKey(chLeft)) {
                    if (freq.get(chLeft) == 0) {
                        remainingMatch++;
                    }
                    freq.put(chLeft, freq.get(chLeft) + 1);
                }
            }
        }

        return minLength == s.length() + 1 ? "" : s.substring(start, start + minLength);
    }
}
