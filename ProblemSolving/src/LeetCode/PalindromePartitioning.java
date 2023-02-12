package LeetCode;


import java.util.ArrayList;
import java.util.List;


public class PalindromePartitioning {
    public static void main(String[] args) {
        System.out.println(partition("aab"));
        System.out.println(partition("a"));
        System.out.println(partition("aaa"));
    }

    public static List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        dfs(res, s, new ArrayList<>(), 0);
        return res;
    }

    private static void dfs(List<List<String>> res, String s, List<String> curr, int p1) {
        if (p1 >= s.length()) {
            res.add(new ArrayList<>(curr));
        }
        for (int p2 = p1; p2 < s.length(); p2++) {
            if (isPalindrome(s, p1, p2)) {
                curr.add(s.substring(p1, p2 + 1));
                dfs(res, s, curr, p2 + 1);
                curr.remove(curr.size() - 1);
            }
        }
    }

    private static boolean isPalindrome(String s, int start, int end) {
        while (start < end) {
            if (s.charAt(start++) != s.charAt(end--)) {
                return false;
            }
        }
        return true;
    }
}
