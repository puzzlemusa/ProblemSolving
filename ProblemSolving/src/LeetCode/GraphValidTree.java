package LeetCode;

import java.util.*;

public class GraphValidTree {
    public static void main(String[] args) {
        System.out.println(isValidTree1(5, new int[][]{{0, 1}, {0, 2}, {0, 3}, {1, 4}}));
        System.out.println(isValidTree1(5, new int[][]{{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}}));
    }

    // Time complexity: O(V + E), space complexity: O(V + E)
    public static boolean isValidTree(int n, int[][] edges) {
        List<Integer>[] adjs = new ArrayList[n];
        for (int[] edge : edges) {
            if (adjs[edge[0]] == null) {
                adjs[edge[0]] = new ArrayList<>();
            }
            if (adjs[edge[1]] == null) {
                adjs[edge[1]] = new ArrayList<>();
            }

            adjs[edge[0]].add(edge[1]);
            adjs[edge[1]].add(edge[0]);
        }

        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (i > 0) {
                    return false;
                }
                if (isCycle(i, -1, adjs, visited)) {
                    return false;
                }
            }
        }

        return true;
    }

    private static boolean isCycle(int n, int parent, List<Integer>[] adjs, boolean[] visited) {
        if (visited[n]) {
            return true;
        }
        visited[n] = true;
        if (adjs[n] == null) {
            return true;
        }
        for (int j : adjs[n]) {
            if (j != parent && isCycle(j, n, adjs, visited)) {
                return true;
            }
        }
        return false;
    }


    // Time complexity: O(V), space complexity: O(V + E)
    public static boolean isValidTree1(int n, int[][] edges) {
        if (n == 0 || n == 1) return true;

        if (edges.length == 0) return false;

        Map<Integer, List<Integer>> adjacencyList = new HashMap<>();
        for (var edge : edges) {
            var node1 = edge[0];
            var node2 = edge[1];
            adjacencyList.putIfAbsent(node1, new ArrayList<>());
            adjacencyList.putIfAbsent(node2, new ArrayList<>());
            adjacencyList.get(node1).add(node2);
            adjacencyList.get(node2).add(node1);
        }

        Set<Integer> visited = new HashSet<>();

        return (
                depthFirstSearch(edges[0][0], -1, visited, adjacencyList) && visited.size() == n
        );
    }

    private static boolean depthFirstSearch(
            int node,
            int previous,
            Set<Integer> visited,
            Map<Integer, List<Integer>> adjacencyList
    ) {
        if (visited.contains(node)) return false;

        visited.add(node);

        for (var neighbor : adjacencyList.get(node)) {
            if (neighbor == previous) continue;

            if (!depthFirstSearch(neighbor, node, visited, adjacencyList)) return false;
        }

        return true;
    }

}
