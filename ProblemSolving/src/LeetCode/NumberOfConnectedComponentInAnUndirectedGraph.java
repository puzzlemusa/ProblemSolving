package LeetCode;

import java.util.ArrayList;
import java.util.List;

public class NumberOfConnectedComponentInAnUndirectedGraph {
    public static void main(String[] args) {
        System.out.println(countComponent1(5, new int[][]{{0, 1}, {1, 2}, {3, 4}}));
        System.out.println(countComponent1(5, new int[][]{{0, 1}, {1, 2}, {2, 3}, {3, 4}}));
    }

    // Time complexity: O(V + E), space complexity: O(V + E)
    public static int countComponent(int n, int[][] edges) {
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
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adjs, visited);
                count++;
            }
        }

        return count;
    }

    private static void dfs(int i, List<Integer>[] adjs, boolean[] visited) {
        if (visited[i]) {
            return;
        }
        visited[i] = true;
        if (adjs[i] == null) {
            return;
        }
        for (int j : adjs[i]) {
            dfs(j, adjs, visited);
        }
    }

    // Time complexity: O(V + E), space complexity: O(V + E)
    public static int countComponent1(int n, int[][] edges) {
        int[] parent = new int[n];
        int[] size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        int count = n;
        for (int[] edge : edges) {
            if (union(parent, size, edge[0], edge[1])) {
                count--;
            }
        }

        return count;
    }

    private static int find(int[] parent, int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent, parent[x]);
    }

    private static boolean union(int[] parent, int[] size, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if (rootX == rootY) {
            return false;
        }
        if (size[x] > size[y]) {
            size[rootX] += size[rootY];
            parent[rootY] = rootX;
        } else {
            size[rootY] += size[rootX];
            parent[rootX] = rootY;
        }
        return true;
    }
}
