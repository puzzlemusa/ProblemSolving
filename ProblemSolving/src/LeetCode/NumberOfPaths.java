package LeetCode;


public class NumberOfPaths {

    public static void main(String[] args) {
        System.out.println(numOfPathsToDest(1));
        System.out.println(numOfPathsToDest(2));
        System.out.println(numOfPathsToDest(3));
        System.out.println(numOfPathsToDest3(4));
        System.out.println(numOfPathsToDest3(5));
        System.out.println(numOfPathsToDest3(6));
    }

    // Time complexity: O(2^(n^2)), space complexity: O(n^2)
    static int numOfPathsToDest(int n) {
        if (n == 1) {
            return 1;
        }
        return dfs(1, 0, n);
    }

    static int dfs(int i, int j, int n) {
        if (i == n - 1 && j == n - 1) {
            return 1;
        }
        if (i >= n || j >= n || j > i) {
            return 0;
        }

        return dfs(i, j + 1, n) + dfs(i + 1, j, n);
    }

    // Time complexity: O(n^2), space complexity: O(n^2)
    static int numOfPathsToDest1(int n) {
        if (n == 1) {
            return 1;
        }
        int[][] dp = new int[n][n];
        return dfs1(1, 0, n, dp);
    }

    static int dfs1(int i, int j, int n, int[][] dp) {
        if (i == n - 1 && j == n - 1) {
            return 1;
        }
        if (i >= n || j >= n || j > i) {
            return 0;
        }

        if (dp[i][j] != 0) {
            return dp[i][j];
        }

        return dp[i][j] = dfs1(i, j + 1, n, dp) + dfs1(i + 1, j, n, dp);
    }

    // Time complexity: O(n^2), space complexity: O(n^2)
    static int numOfPathsToDest2(int n) {
        if (n == 1) {
            return 1;
        }
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= i; j++) {
                if (i == j) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }

        return dp[n - 1][n - 1];
    }

    // Time complexity: O(n^2), space complexity: O(n)
    static int numOfPathsToDest3(int n) {
        if (n == 1) {
            return 1;
        }
        int[] last = new int[n];
        int[] curr = new int[n];
        for (int i = 1; i < n; i++) {
            curr[0] = 1;
            for (int j = 1; j <= i; j++) {
                if (i == j) {
                    curr[j] = curr[j - 1];
                    last[j] = curr[j];
                } else {
                    curr[j] = curr[j - 1] + last[j];
                    last[j] = curr[j];
                }
            }
        }

        return curr[n - 1];
    }
}
