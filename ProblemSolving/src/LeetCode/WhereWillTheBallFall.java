package LeetCode;


public class WhereWillTheBallFall {

    public static void main(String[] args) {
        System.out.println(findBall(new int[][]{{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}}));
        System.out.println(findBall(new int[][]{{-1}}));
        System.out.println(findBall(new int[][]{{1}}));
        System.out.println(findBall(new int[][]{{1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}, {1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}}));
    }

    public static int[] findBall(int[][] grid) {
        int[][] mem = new int[grid.length + 1][grid[0].length];
        for (int i = 0; i < grid[0].length; i++) {
            mem[grid.length][i] = i;
        }

        for (int i = grid.length - 1; i >= 0; i--) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == -1) {
                    if (j == 0) {
                        mem[i][j] = -1;
                    } else if (grid[i][j - 1] == 1) {
                        mem[i][j] = -1;
                    } else {
                        mem[i][j] = mem[i + 1][j - 1];
                    }
                } else if (grid[i][j] == 1) {
                    if (j == grid[i].length - 1) {
                        mem[i][j] = -1;
                    } else if (grid[i][j + 1] == -1) {
                        mem[i][j] = -1;
                    } else {
                        mem[i][j] = mem[i + 1][j + 1];
                    }
                }
            }
        }
        return mem[0];
    }
}
