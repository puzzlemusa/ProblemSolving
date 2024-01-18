package LeetCode;


import java.util.Arrays;

public class WallsAndGates {

    public static void main(String[] args) {
        System.out.println(Arrays.deepToString(wallsAndGates(new int[][]{
                {2147483647, -1, 0, 2147483647},
                {2147483647, 2147483647, 2147483647, -1},
                {2147483647, -1, 2147483647, -1},
                {0, -1, 2147483647, 2147483647},
        })));
    }

    // Time complexity: O(mn), space complexity: O(mn)
    public static int[][] wallsAndGates(int[][] rooms) {
        int[][] res = new int[rooms.length][rooms[0].length];
        for (int row = 0; row < rooms.length; row++) {
            for (int col = 0; col < rooms[0].length; col++) {
                if (rooms[row][col] == 2147483647) {
                    res[row][col] = dfs(rooms, row, col, new boolean[rooms.length][rooms[0].length]);
                } else {
                    res[row][col] = rooms[row][col];
                }
            }
        }
        return res;
    }

    private static int dfs(int[][] rooms, int row, int col, boolean[][] visited) {
        if (row < 0 || row >= rooms.length || col < 0 || col >= rooms[0].length || rooms[row][col] == -1 || visited[row][col]) {
            return -1;
        }

        if (rooms[row][col] == 0) {
            return 0;
        }

        visited[row][col] = true;

        int min = 2147483647;
        for (int[] dir : dirs) {
            int nextRow = row + dir[0];
            int nextCol = col + dir[1];
            int res = dfs(rooms, nextRow, nextCol, visited);
            if (res != -1 && res != 2147483647) {
                min = Math.min(min, res + 1);
            }
        }

        return min;
    }

    static int[][] dirs = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
}
