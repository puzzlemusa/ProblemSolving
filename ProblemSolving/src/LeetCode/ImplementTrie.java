package LeetCode;


public class ImplementTrie {

    private static Node root;

    public static void main(String[] args) {
        Trie();
        insert("apple");
        System.out.println(search("apple"));
        System.out.println(search("app"));
        System.out.println(startsWith("app"));
        insert("app");
        System.out.println(search("app"));
    }

    public static void Trie() {
        root = new Node('@');
    }

    // Time complexity: O(n), space complexity: O(n). n is the length of the word.
    public static void insert(String word) {
        Node curr = root;
        for (char ch : word.toCharArray()) {
            if (curr.children[ch - 'a'] == null) {
                curr.children[ch - 'a'] = new Node(ch);
            }
            curr = curr.children[ch - 'a'];
        }
        curr.isWord = true;
    }

    // Time complexity: O(n), space complexity: O(1). n is the length of the word.
    public static boolean search(String word) {
        Node last = getLast(word);
        return last != null && last.isWord;
    }

    // Time complexity: O(n), space complexity: O(1). n is the length of the prefix.
    public static boolean startsWith(String prefix) {
        Node last = getLast(prefix);
        return last != null;
    }

    private static Node getLast(String word) {
        Node curr = root;
        for (char ch : word.toCharArray()) {
            if (curr.children[ch - 'a'] == null) {
                return null;
            }
            curr = curr.children[ch - 'a'];
        }
        return curr;
    }

    public static class Node {
        char val;
        boolean isWord;

        Node[] children;


        Node(char val) {
            this.val = val;
            this.children = new Node[26];
        }
    }
}
