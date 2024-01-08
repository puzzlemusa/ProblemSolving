package AlgorithmPractice;

public class KnapSackAlgorithm {

    // Time complexity: O(2^n), Space complexity: O(n)
    private static int recursive(int weights[], int values[], int capacity, int index) {
        if (index >= weights.length || capacity == 0) {
            return 0;
        }

        if (weights[index] > capacity) {
            return recursive(weights, values, capacity, index + 1);
        } else {
            return Math.max(
                    values[index] + recursive(weights, values, capacity - weights[index], index + 1),
                    recursive(weights, values, capacity, index + 1)
            );
        }

    }

    // Time complexity: O(n * capacity), Space complexity: O(n * capacity)
    private static int recursiveDP(int[] weights, int[] values, int capacity, int index, int[][] dp) {
        if (index >= weights.length || capacity == 0) {
            return 0;
        }

        if (dp[index][capacity] != 0)
            return dp[index][capacity];

        if (weights[index] > capacity) {
            return dp[index][capacity] = recursiveDP(weights, values, capacity, index + 1, dp);
        } else {
            return dp[index][capacity] = Math.max(
                    values[index] + recursiveDP(weights, values, capacity - weights[index], index + 1, dp),
                    recursiveDP(weights, values, capacity, index + 1, dp)
            );
        }

    }

    // Time complexity: O(n * capacity), Space complexity: O(n * capacity)
    private static int iterative1(int[] weights, int[] values, int capacity) {
        int[][] dp = new int[weights.length + 1][capacity + 1];

        for (int i = 0; i <= weights.length; i++) {
            for (int w = 0; w <= capacity; w++) {
                if (i == 0 || w == 0) {
                    dp[i][w] = 0;
                } else if (weights[i - 1] <= w) {
                    dp[i][w] = Math.max(
                            values[i - 1] + dp[i - 1][w - weights[i - 1]],
                            dp[i - 1][w]
                    );
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        return dp[weights.length][capacity];
    }

    // Time complexity: O(n * capacity), Space complexity: O(capacity)
    private static int iterative2(int[] weights, int[] values, int capacity) {
        int[] dp = new int[capacity + 1];

        for (int i = 1; i <= weights.length; i++) {
            for (int w = capacity; w >= 0; w--) {
                if (weights[i - 1] <= w) {
                    dp[w] = Math.max(values[i - 1] + dp[w - weights[i - 1]], dp[w]);
                }
            }
        }

        return dp[capacity];
    }

    public static void main(String[] args) {
        System.out.println(recursive(new int[]{10, 20, 30}, new int[]{60, 100, 120}, 50, 0));
        System.out.println(recursiveDP(new int[]{10, 20, 30}, new int[]{60, 100, 120}, 50, 0, new int[4][51]));
        System.out.println(iterative1(new int[]{10, 20, 30}, new int[]{60, 100, 120}, 50));
        System.out.println(iterative2(new int[]{10, 20, 30}, new int[]{60, 100, 120}, 50));
    }
}
