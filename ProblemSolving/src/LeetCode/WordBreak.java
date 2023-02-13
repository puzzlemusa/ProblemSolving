package LeetCode;


import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class WordBreak {
    public static void main(String[] args) {
        System.out.println(wordBreak("leetcode", List.of("leet", "code")));
        System.out.println(wordBreak("applepenapple", List.of("apple", "pen")));
        System.out.println(wordBreak("catsandog", List.of("cats", "dog", "sand", "and", "cat")));
        System.out.println(wordBreak("aa", List.of("a", "aaa")));
        System.out.println(wordBreak("a", List.of("a")));
        System.out.println(wordBreak("a", List.of("b")));
        System.out.println(wordBreak("abcd", List.of("ab", "abc", "d")));
        System.out.println(wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", List.of("a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa")));
        System.out.println(wordBreak("aaaab", List.of("a", "aa")));
        System.out.println(wordBreak("catsandogcat", List.of("cats", "dog", "sand", "and", "cat", "an")));
    }

    private static Boolean[] mem;

    public static boolean wordBreak(String s, List<String> wordDict) {
        mem = new Boolean[s.length()];
        return find(s, new HashSet<>(wordDict), 0);
    }

    private static boolean find(String s, Set<String> wordDict, int start) {
        if (start == s.length()) {
            return true;
        }
        if (mem[start] != null) {
            return mem[start];
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (wordDict.contains(s.substring(start, end)) && find(s, wordDict, end)) {
                return mem[start] = true;
            }
        }
        return mem[start] = false;
    }
}
