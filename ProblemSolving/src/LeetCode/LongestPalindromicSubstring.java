package LeetCode;


public class LongestPalindromicSubstring {
    public static void main(String[] args) {
        System.out.println(longestPalindrome("babad"));
        System.out.println(longestPalindrome("cbbd"));
    }

    // Time complexity: O(n^2), Space complexity: O(1)
    public static String longestPalindrome(String s) {
        int maxLen = 0;
        String res = "";

        for (int i = 0; i < s.length(); i++) {
            int left = i;
            int right = i;
            while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
                if (maxLen < right - left + 1) {
                    maxLen = right - left + 1;
                    res = s.substring(left, right + 1);
                }
                left--;
                right++;
            }

            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
                if (maxLen < right - left + 1) {
                    maxLen = right - left + 1;
                    res = s.substring(left, right + 1);
                }
                left--;
                right++;
            }
        }

        return res;
    }
}
