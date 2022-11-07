package LeetCode;

public class IsSubsequence {
    public static void main(String[] args) {
        System.out.println(isSubsequence("abc", "ahbgdc"));
        System.out.println(isSubsequence("axc", "ahbgdc"));
    }

    public static boolean isSubsequence(String s, String t) {
        int s_i = 0;
        int t_i = 0;

        while (s_i < s.length() && t_i < t.length()) {
            if (s.charAt(s_i) == t.charAt(t_i)) {
                s_i++;
            }
            t_i++;
        }
        return s_i == s.length();
    }
}
