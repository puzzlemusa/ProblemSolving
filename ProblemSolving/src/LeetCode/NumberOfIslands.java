package LeetCode;

public class NumberOfIslands {

    public static void main(String[] args) {
        char[][] grid1 = new char[][]{{'1', '1', '1', '1', '0'},
                {'1', '1', '0', '1', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'}};

        char[][] grid2 = {{'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}
        };

        char[][] grid3 = {{'1', '1', '1'}, {'0', '1', '0'}, {'1', '1', '1'}};

        System.out.println(numIslands(grid1));
        System.out.println(numIslands(grid2));
        System.out.println(numIslands(grid3));
    }

    // Time complexity: O(n*m), space complexity: O(n*m)
    public static int numIslands(char[][] grid) {
        int total = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == '1') {
                    total++;
                    DFS(i, j, grid);
                }
            }
        }

        return total;
    }

    public static void DFS(int i, int j, char[][] grid) {
        grid[i][j] = '0';

        if (j + 1 < grid[i].length && grid[i][j + 1] == '1')
            DFS(i, j + 1, grid);
        if (i + 1 < grid.length && grid[i + 1][j] == '1')
            DFS(i + 1, j, grid);
        if (j > 0 && grid[i][j - 1] == '1')
            DFS(i, j - 1, grid);
        if (i > 0 && grid[i - 1][j] == '1')
            DFS(i - 1, j, grid);
    }
}
