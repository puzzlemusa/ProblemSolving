package LeetCode;

import java.util.*;

public class WordLadder {
    public static void main(String[] args) {
        System.out.println(ladderLength1("hog", "cog", List.of("cog")));
        System.out.println(ladderLength1("kiss", "tusk", List.of("miss", "dusk", "kiss", "musk", "tusk", "diss", "disk", "sang", "ties", "muss")));
        System.out.println(ladderLength1("hit", "cog", List.of("hot", "dot", "dog", "lot", "log", "cog")));
        System.out.println(ladderLength1("hit", "cog", List.of("hot", "dot", "dog", "lot", "log")));
        System.out.println(ladderLength1("a", "c", List.of("a", "b", "c")));
    }

    // WA. 42/51 test cases passed.
    // Time complexity: O(n^2*M), space complexity: O(n * M), M = length of word
    public static int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Map<String, List<String>> adjList = new HashMap<>();
        Map<String, Integer> res = new HashMap<>();
        for (int i = 0; i < wordList.size(); i++) {
            String curr = wordList.get(i);
            res.put(curr, -1);
            for (int j = i + 1; j < wordList.size(); j++) {
                String adjWord = wordList.get(j);
                if (i != j && isAdjacent(curr, adjWord)) {
                    adjList.computeIfAbsent(curr, k -> new ArrayList<>()).add(adjWord);
                    adjList.computeIfAbsent(adjWord, k -> new ArrayList<>()).add(curr);
                }
            }
        }

        if (adjList.get(endWord) == null) {
            return 0;
        }

        int min = wordList.size() + 1;
        for (String s : wordList) {
            if (beginWord.equals(s)) {
                min = Math.min(min, dfs(s, endWord, adjList, res));
            } else if (isAdjacent(beginWord, s)) {
                min = Math.min(min, dfs(s, endWord, adjList, res) + 1);
            }
        }

        return min >= wordList.size() + 1 ? 0 : min;

    }

    private static int dfs(String word, String endWord, Map<String, List<String>> adjList, Map<String, Integer> res) {
        if (word.equals(endWord)) {
            return 1;
        }
        if (res.get(word) != -1) {
            return res.get(word);
        }

        if (!adjList.containsKey(word) || adjList.get(word).isEmpty()) {
            res.put(word, res.size() + 1);
            return res.size() + 1;
        }

        res.put(word, res.size() + 1);
        int min = res.size() + 1;
        for (String s : adjList.get(word)) {
            min = Math.min(min, dfs(s, endWord, adjList, res) + 1);
        }
        res.put(word, min);
        return min;
    }

    // Time complexity: O(n^2*M + V + E), space complexity: O(n * M), M = length of word
    public static int ladderLength1(String beginWord, String endWord, List<String> wordList) {
        Map<String, List<String>> adjList = new HashMap<>();
        for (int i = 0; i < wordList.size(); i++) {
            String curr = wordList.get(i);
            if (isAdjacent(beginWord, curr)) {
                adjList.computeIfAbsent(beginWord, k -> new ArrayList<>()).add(curr);
            }

            for (int j = i + 1; j < wordList.size(); j++) {
                String adjWord = wordList.get(j);
                if (i != j && isAdjacent(curr, adjWord)) {
                    adjList.computeIfAbsent(curr, k -> new ArrayList<>()).add(adjWord);
                    adjList.computeIfAbsent(adjWord, k -> new ArrayList<>()).add(curr);
                }
            }
        }

        Set<String> visited = new HashSet<>();
        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);
        int length = 0;

        while (!queue.isEmpty()) {
            ++length;
            int n = queue.size();
            while (n-- > 0) {
                String curr = queue.poll();
                if (curr.equals(endWord)) {
                    return length;
                }
                visited.add(curr);
                if (adjList.get(curr) != null) {
                    for (String s : adjList.get(curr)) {
                        if (!visited.contains(s)) {
                            queue.add(s);
                        }
                    }
                }
            }
        }

        return 0;

    }

    private static boolean isAdjacent(String a, String b) {
        if (a.length() != b.length()) {
            return false;
        }

        int diffCount = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                diffCount++;
                if (diffCount > 1) {
                    return false;
                }
            }
        }

        return diffCount == 1;
    }
}
