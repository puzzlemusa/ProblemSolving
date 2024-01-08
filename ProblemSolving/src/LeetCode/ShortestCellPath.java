package LeetCode;


import java.util.LinkedList;
import java.util.Queue;

public class ShortestCellPath {
    static int[][] dirs = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public static void main(String[] args) {
        System.out.println(shortestCellPath1(new int[][]{{1, 1, 1}, {0, 0, 0}, {0, 0, 0}}, 0, 1, 0, 0));
        System.out.println(shortestCellPath1(new int[][]{{1, 1, 1}, {0, 0, 1}, {1, 1, 1}}, 0, 0, 2, 0));
        System.out.println(shortestCellPath1(new int[][]{{1, 1, 1, 1}, {0, 0, 0, 1}, {1, 1, 1, 1}}, 0, 0, 2, 0));
        System.out.println(shortestCellPath1(new int[][]{{1, 1, 1, 1}, {0, 0, 0, 1}, {1, 0, 1, 1}}, 0, 0, 2, 0));
    }

    //https://www.pramp.com/challenge/Y56aZmaj9Ptmd9wV9xvL
    static int shortestCellPath(int[][] grid, int sr, int sc, int tr, int tc) {
        // your code goes here
        int res = dfs(grid, sr, sc, tr, tc, new boolean[grid.length][grid[0].length]);
        return res > grid.length * grid[0].length ? -1 : res;
    }

    // Time complexity: O(n*m), space complexity: O(n*m)
    static int dfs(int[][] grid, int sr, int sc, int tr, int tc, boolean[][] seen) {
        if (sr < 0 || sc < 0 || sr >= grid.length || sc >= grid[0].length || seen[sr][sc] || grid[sr][sc] == 0) {
            return grid.length * grid[0].length + 1;
        }

        seen[sr][sc] = true;

        if (sr == tr && sc == tc) {
            return 0;
        }

        int min = grid.length * grid[0].length + 1;
        for (int[] dir : dirs) {
            int cost = dfs(grid, sr + dir[0], sc + dir[1], tr, tc, seen) + 1;
            min = Math.min(min, cost);
        }
        return min;
    }

    // Time complexity: O(n*m), space complexity: O(n*m)
    static int shortestCellPath1(int[][] grid, int sr, int sc, int tr, int tc) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{sr, sc});

        int res = 0;
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int[] loc = q.poll();
                int x = loc[0];
                int y = loc[1];
                if (x == tr && y == tc) {
                    return res;
                }
                grid[x][y] = 0;
                for (int[] dir : dirs) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];
                    if (newX < 0 || newY < 0 || newX >= grid.length || newY >= grid[0].length || grid[newX][newY] == 0) {
                        continue;
                    }
                    q.offer(new int[]{newX, newY});
                }
            }
            res++;
        }

        return -1;
    }
}
