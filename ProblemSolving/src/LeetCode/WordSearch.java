package LeetCode;


public class WordSearch {

    public static void main(String[] args) {
        System.out.println(exist(new char[][]{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCCED"));
        System.out.println(exist(new char[][]{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "SEE"));
        System.out.println(exist(new char[][]{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCB"));
    }

    // Time complexity: O(m*n*4^s), Space complexity: O(s) s= word.length()
    public static boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (search(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    private static boolean search(char[][] board, String word, int i, int j, int index) {
        if (index == word.length()) {
            return true;
        }

        if (i >= board.length || i < 0 || j >= board[i].length || j < 0 || board[i][j] != word.charAt(index)) {
            return false;
        }

        boolean exist = false;
        if (board[i][j] == word.charAt(index)) {
            board[i][j] += 100;
            exist = search(board, word, i + 1, j, index + 1) ||
                    search(board, word, i, j + 1, index + 1) ||
                    search(board, word, i - 1, j, index + 1) ||
                    search(board, word, i, j - 1, index + 1);
            board[i][j] -= 100;
        }
        return exist;
    }
}
