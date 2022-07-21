package LeetCode;

import java.util.HashSet;
import java.util.Set;

public class LongestSubstringWithoutRepeatingCharacters {
    public static void main(String[] args) {
        System.out.println(lengthOfLongestSubstring("tmmzuxt"));
        System.out.println(lengthOfLongestSubstring("pwwkew"));
        System.out.println(lengthOfLongestSubstring("abcabcbb"));
        System.out.println(lengthOfLongestSubstring("bbbbb"));
        System.out.println(lengthOfLongestSubstring(""));
        System.out.println(lengthOfLongestSubstring("mississippi"));
        System.out.println(lengthOfLongestSubstring("a"));

        System.out.println("-----------------------------");
        System.out.println(lengthOfLongestSubstringWithOutSet("tmmzuxt"));
        System.out.println(lengthOfLongestSubstringWithOutSet("pwwkew"));
        System.out.println(lengthOfLongestSubstringWithOutSet("abcabcbb"));
        System.out.println(lengthOfLongestSubstringWithOutSet("bbbbb"));
        System.out.println(lengthOfLongestSubstringWithOutSet(""));
        System.out.println(lengthOfLongestSubstringWithOutSet("mississippi"));
        System.out.println(lengthOfLongestSubstringWithOutSet("a"));
    }

    public static int lengthOfLongestSubstring(String s) {
        int subLen = 0;
        int maxVal = 0;
        int left = 0;
        int right = 0;

        Set<Character> charSet = new HashSet<>();
        while (right < s.length()) {
            if (!charSet.contains(s.charAt(right))) {
                charSet.add(s.charAt(right));
                subLen++;
                maxVal = Math.max(maxVal, subLen);
            } else {
                while (s.charAt(left) != (s.charAt(right))) {
                    charSet.remove(s.charAt(left));
                    left++;
                    subLen--;
                }
                left++;
            }
            right++;
        }

        return maxVal;
    }

    // host last duplicate position.
    public static int lengthOfLongestSubstringWithOutSet(String s) {
        int result = 0;
        int lastPlace = 0;
        int[] cache = new int[256];
        for (int i = 0; i < s.length(); i++) {
            lastPlace = Math.max(lastPlace, cache[s.charAt(i)]);
            cache[s.charAt(i)] = i + 1;
            result = Math.max(result, i - lastPlace + 1);
        }
        return result;
    }
}
