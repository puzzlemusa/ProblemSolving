package LeetCode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MaxAreaOfIsland {

    public static void main(String[] args) {
        System.out.println(maxAreaOfIsland(new int[][]{
                {1, 1, 1, 1, 0},
                {1, 1, 0, 1, 0},
                {1, 1, 0, 0, 0},
                {0, 0, 0, 1, 1}}));
    }

    // Time complexity: O(n*m), space complexity: O(n*m)
    public static int maxAreaOfIsland(int[][] grid) {
        int max = 0;
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(grid[i][j] == 1){
                    max = Math.max(max, DFS(grid, i, j));
                }
            }
        }

        return max;
    }

    private static int DFS(int[][] grid, int x, int y){
        if(x<0 || x>= grid.length || y<0 || y>=grid[0].length || grid[x][y] == 0){
            return 0;
        }

        grid[x][y] = 0;
        return DFS(grid, x+1, y) + DFS(grid, x-1, y) + DFS(grid, x, y+1) + DFS(grid, x, y-1) + 1;
    }

}
