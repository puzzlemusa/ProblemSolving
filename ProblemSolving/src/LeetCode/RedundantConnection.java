package LeetCode;


import java.util.Arrays;

public class RedundantConnection {

    public static void main(String[] args) {
        System.out.println(Arrays.toString(findRedundantConnection(new int[][]{{1, 2}, {1, 3}, {2, 3}})));
        System.out.println(Arrays.toString(findRedundantConnection(new int[][]{{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}})));
    }

    static int[] parent;
    static int[] size;

    // Time complexity: O(V), space complexity: O(V)
    public static int[] findRedundantConnection(int[][] edges) {
        parent = new int[edges.length + 1];
        size = new int[edges.length + 1];
        for (int i = 1; i <= edges.length; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        for (int[] edge : edges) {
            if (!union(edge[0], edge[1])) {
                return edge;
            }
        }

        return new int[0];
    }

    private static int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    private static boolean union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
        if (size[rootX] > size[rootY]) {
            size[rootX] += size[rootY];
            parent[rootY] = rootX;
        } else {
            size[rootY] += size[rootX];
            parent[rootX] = rootY;
        }
        return true;
    }
}
