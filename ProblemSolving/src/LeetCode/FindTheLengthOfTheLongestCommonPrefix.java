package LeetCode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

public class FindTheLengthOfTheLongestCommonPrefix {

    public static void main(String[] args) {
        System.out.println(longestCommonPrefix1(new int[]{1, 10, 100}, new int[]{1000}));
        System.out.println(longestCommonPrefix1(new int[]{1, 2, 3}, new int[]{4, 4, 4}));
    }

    // Time complexity O(m * log10(max_value_in_arr1) + n * (log10(max_value_in_arr2) + k^2)).
    // Space complexity O(m * log10(max_value_in_arr1)), where m is the number of elements in arr1.
    public static int longestCommonPrefix(int[] arr1, int[] arr2) {
        Set<Integer> uniquePrefixes = new HashSet<>();
        for (int item : arr1) {
            while (item > 0) {
                uniquePrefixes.add(item);
                item /= 10;
            }
        }

        int result = 0;
        for (int item : arr2) {
            String str = String.valueOf(item);
            for (int i = str.length(); i > 0; i--) {
                int prefix = Integer.parseInt(str.substring(0, i));
                if (uniquePrefixes.contains(prefix)) {
                    result = Math.max(result, i);
                }
            }
        }

        return result;
    }

    // Time complexity O(m * log10(max_value_in_arr1) + n * (log10(max_value_in_arr2))).
    public static int longestCommonPrefix1(int[] arr1, int[] arr2) {
        Trie trie = new Trie();
        for (var a : arr1) {
            trie.insert(String.valueOf(a));
        }

        int result = 0;
        for (var a : arr2) {
            result = Math.max(result, trie.search(String.valueOf(a)));
        }
        return result;
    }

    static class Trie {

        Node root;

        public Trie() {
            root = new Node('*', false, new HashMap<>());
        }

        public void insert(String s) {
            Node curr = root;
            int n = s.length();
            for (int i = 0; i < n; i++) {
                HashMap<Character, Node> hp = curr.children;
                char ch = s.charAt(i);
                if (hp.containsKey(ch)) {
                    curr = hp.get(ch);
                } else {
                    Node node = new Node(ch, i == n - 1, new HashMap<>());
                    hp.put(ch, node);
                    curr = node;
                }
            }
            curr.terminal = true;
        }

        public int search(String s) {
            Node curr = root;
            int n = s.length();
            int count = 0;
            for (int i = 0; i < n; i++) {
                char ch = s.charAt(i);
                HashMap<Character, Node> hp = curr.children;
                if (hp.containsKey(ch)) {
                    curr = hp.get(ch);
                    count++;
                } else {
                    return count;
                }
            }
            return count;
        }
    }

    static class Node {
        char ch;
        boolean terminal;
        HashMap<Character, Node> children;

        Node(char ch, boolean terminal, HashMap<Character, Node> children) {
            this.ch = ch;
            this.terminal = terminal;
            this.children = children;
        }
    }
}
