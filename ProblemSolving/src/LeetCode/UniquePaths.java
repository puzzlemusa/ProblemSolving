package LeetCode;

public class UniquePaths {
    public static void main(String[] args) {
        System.out.println(uniquePaths(3, 7));
        System.out.println(uniquePaths(3, 2));

        System.out.println("---------------------------");

        System.out.println(uniquePaths1(3, 7));
        System.out.println(uniquePaths1(3, 2));
    }

    public static int uniquePaths(int m, int n) {
        int[][] mem = new int[m][n];
        return calc(0, 0, mem, m, n);
    }

    public static int calc(int x, int y, int[][] mem, int m, int n) {
        if (mem[x][y] != 0) {
            return mem[x][y];
        } else if (x == m - 1 && y == n - 1) {
            return 1;
        } else {
            int down = 0;
            int right = 0;
            if (x < m - 1) {
                down = calc(x + 1, y, mem, m, n);
            }
            if (y < n - 1) {
                right = calc(x, y + 1, mem, m, n);
            }
            return mem[x][y] = down + right;
        }
    }

    public static int uniquePaths1(int m, int n) {
        int[][] mem = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(i==0){
                    mem[0][j] = 1;
                }
                if(j==0){
                    mem[i][0] = 1;
                }
                if(i != 0 && j != 0){
                    mem[i][j] = mem[i-1][j] + mem[i][j-1];
                }
            }
        }

        return mem[m-1][n-1];
    }
}
