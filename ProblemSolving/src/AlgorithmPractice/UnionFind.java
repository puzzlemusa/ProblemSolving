package AlgorithmPractice;

public class UnionFind {

    private static int[] parent;
    private static int[] size;

    // Time complexity: O(logN), space complexity: O(N)
    // With path compression and union by rank: Amortized O(α(n)),
    // where α(n) is the inverse Ackermann function,
    // which grows extremely slowly (less than 5 for any practical value of n).
    public static void main(String[] args) {
        parent = new int[5];
        size = new int[5];
        for (int i = 0; i < 5; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        union(0, 1);
        union(1, 2);
        union(3, 4);
    }

    // Path compression, time complexity: O(logN) Or O(α(n)), where α(n) is the inverse Ackermann function.
    private static int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    //Using size. Time complexity: O(N)
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
