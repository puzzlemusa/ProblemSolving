package LeetCode;


public class PalindromicSubstrings {
    public static void main(String[] args) {
        System.out.println(countSubstrings1("abc"));
        System.out.println(countSubstrings1("aaa"));
    }

    // Time complexity: O(n^3), Space complexity: O(1)
    public static int countSubstrings(String s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                String sub = s.substring(i, j);
                if (sub.equals(new StringBuilder(sub).reverse().toString())) {
                    res++;
                }
            }
        }

        return res;
    }

    // Time complexity: O(n^2), Space complexity: O(n^2)
    public static int countSubstrings1(String s) {
        int res = 0;
        boolean[][] isPalindrome = new boolean[s.length()][s.length()];
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j >= 0; j--) {
                if (i == j) {
                    res++;
                    isPalindrome[i][j] = true;
                } else if (s.charAt(i) == s.charAt(j)) {
                    if (i - j == 1) {
                        res++;
                        isPalindrome[i][j] = true;
                    } else {
                        isPalindrome[i][j] = isPalindrome[i - 1][j + 1];
                        if (isPalindrome[i][j]) {
                            res++;
                        }
                    }
                }
            }
        }

        return res;
    }

    // Time complexity: O(n^2), Space complexity: O(1)
    public int countSubstrings2(String s) {
        if (s.length() < 2) {
            return s.length();
        }
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            // Odd Length
            int left = i, right = i;
            while (
                    left >= 0 &&
                            right < s.length() &&
                            s.charAt(left) == s.charAt(right)
            ) {
                result++;
                left--;
                right++;
            }
            // Even Length
            left = i;
            right = i + 1;
            while (
                    left >= 0 &&
                            right < s.length() &&
                            s.charAt(left) == s.charAt(right)
            ) {
                result++;
                left--;
                right++;
            }
        }
        return result;
    }
}
