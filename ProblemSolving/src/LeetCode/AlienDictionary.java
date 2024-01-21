package LeetCode;

import java.util.*;

public class AlienDictionary {

    static Map<Character, Set<Character>> adjList;
    static Map<Character, Set<Character>> revList;
    static Map<Character, Integer> degrees;

    public static void main(String[] args) {
        System.out.println(alienOrder(new String[]{"wrt", "wrf", "er", "ett", "rftt"}));
        System.out.println(alienOrder(new String[]{"z", "x"}));
        System.out.println(alienOrder(new String[]{"z", "x", "z"}));
    }

    public static String alienOrder(String[] words) {
        initialize(words);

        if (createEdges(words) == false) return "";

        createDegrees();

        List<Character> ordering = topologicalSort();

        if (ordering == null) return "";

        return getString(ordering);
    }

    private static boolean createEdges(String first, String second) {
        int minLen = Math.min(first.length(), second.length());

        for (int i = 0; i < minLen; i++) {
            char firstChar = first.charAt(i);
            char secondChar = second.charAt(i);

            if (firstChar != secondChar) {
                Set<Character> edges = adjList.get(firstChar);
                edges.add(secondChar);
                adjList.put(firstChar, edges);

                Set<Character> revEdges = revList.get(secondChar);
                revEdges.add(firstChar);
                revList.put(secondChar, revEdges);

                return true;
            }
        }

        return (first.length() <= second.length());
    }

    private static void initialize(String[] words) {
        int n = words.length;
        adjList = new HashMap<>();
        revList = new HashMap<>();
        degrees = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (char c : words[i].toCharArray()) {
                adjList.put(c, new HashSet<>());
                revList.put(c, new HashSet<>());
                degrees.put(c, 0);
            }
        }
    }

    private static boolean createEdges(String[] words) {
        int n = words.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (createEdges(words[i], words[j]) == false) return false;
            }
        }
        return true;
    }

    private static void createDegrees() {
        for (char c : adjList.keySet()) {
            degrees.put(c, adjList.get(c).size());
        }
    }

    private static List<Character> topologicalSort() {
        Queue<Character> queue = new LinkedList<>();

        List<Character> ordering = new ArrayList<>();

        for (char c : degrees.keySet()) {
            if (degrees.get(c) == 0) {
                queue.add(c);
            }
        }

        if (queue.isEmpty()) {
            return null;
        }

        while (!queue.isEmpty()) {
            int qSize = queue.size();

            for (int i = 0; i < qSize; i++) {
                char removed = queue.remove();

                ordering.add(removed);

                for (char neighbor : revList.get(removed)) {
                    int degree = degrees.get(neighbor);
                    degree--;

                    if (degree == 0) queue.add(neighbor);

                    degrees.put(neighbor, degree);
                }
            }
        }

        if (ordering.size() < revList.size()) {
            return null;
        }

        return ordering;
    }

    private static String getString(List<Character> ordering) {
        StringBuilder bld = new StringBuilder();
        for (char c : ordering) bld.append(c);
        return bld.reverse().toString();
    }
}
