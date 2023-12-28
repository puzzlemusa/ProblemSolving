package LeetCode;


import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class RottingOranges {
    public static void main(String[] args) {
        System.out.println(orangesRotting(new int[][]{
                {2, 1, 1},
                {1, 1, 0},
                {0, 1, 1}}));
        System.out.println(orangesRotting(new int[][]{
                {2, 1, 1},
                {0, 1, 1},
                {1, 0, 1}}));
        System.out.println(orangesRotting(new int[][]{
                {0, 2}}));
    }

    public static int orangesRotting(int[][] grid) {
        Queue<List<Integer>> q = new LinkedList<>();
        int minutes = 0;
        int freshOrange = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 2) {
                    q.offer(List.of(i, j));
                }
                if (grid[i][j] == 1) {
                    freshOrange++;
                }
            }
        }

        int[][] dirs = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty() && freshOrange > 0) {
            int n = q.size();
            while (n-- > 0) {
                List<Integer> rot = q.poll();
                int x = rot.get(0);
                int y = rot.get(1);
                for (int[] dir : dirs) {
                    int x1 = x + dir[0];
                    int y1 = y + dir[1];
                    if (isValid(grid, x1, y1)) {
                        grid[x1][y1] = 2;
                        freshOrange--;
                        q.offer(List.of(x1, y1));
                    }
                }
            }
            minutes++;
        }

        return freshOrange == 0 ? minutes : -1;
    }

    private static boolean isValid(int[][] grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.length || y >= grid[0].length || grid[x][y] == 0 || grid[x][y] == 2) {
            return false;
        } else {
            return true;
        }
    }
}
