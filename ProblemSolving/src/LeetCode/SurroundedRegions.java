package LeetCode;


import java.util.Arrays;

public class SurroundedRegions {

    public static void main(String[] args) {
        char[][] chars = {
                {'X', 'X', 'X', 'X'},
                {'X', 'O', 'O', 'X'},
                {'X', 'X', 'O', 'X'},
                {'X', 'O', 'X', 'X'}};
        solve(chars);
        System.out.println(Arrays.deepToString(chars));
        char[][] chars1 = {
                {'O', 'O', 'O'},
                {'O', 'O', 'O'},
                {'O', 'O', 'O'}};
        solve(chars1);
        System.out.println(Arrays.deepToString(chars1));
        char[][] chars2 = {
                {'X', 'O', 'X'},
                {'O', 'X', 'O'},
                {'X', 'O', 'X'}};
        solve(chars2);
        System.out.println(Arrays.deepToString(chars2));
        char[][] chars3 = {
                {'O', 'O', 'O', 'O', 'X', 'X'},
                {'O', 'O', 'O', 'O', 'O', 'O'},
                {'O', 'X', 'O', 'X', 'O', 'O'},
                {'O', 'X', 'O', 'O', 'X', 'O'},
                {'O', 'X', 'O', 'X', 'O', 'O'},
                {'O', 'X', 'O', 'O', 'O', 'O'}};
        solve(chars3);
        System.out.println(Arrays.deepToString(chars3));
    }

    public static void solve(char[][] board) {
        int m = board.length;

        if (m == 0) return;

        int n = board[0].length;

        //Moving over firts and last column
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                DFS(board, i, 0);
            if (board[i][n - 1] == 'O')
                DFS(board, i, n - 1);
        }


        //Moving over first and last row
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                DFS(board, 0, j);
            if (board[m - 1][j] == 'O')
                DFS(board, m - 1, j);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
    }

    private static void DFS(char[][] board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.length || j >= board[0].length || board[i][j] != 'O') {
            return;
        }
        board[i][j] = '#';
        DFS(board, i - 1, j);
        DFS(board, i + 1, j);
        DFS(board, i, j - 1);
        DFS(board, i, j + 1);
    }
}
